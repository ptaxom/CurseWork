#include "kernelfiltereditor.h"
#include "ui_kernelfiltereditor.h"


KernelFilterEditor::KernelFilterEditor(ImageController *controller_, int index_, QWidget *parent):
    QDialog(parent),
    ui(new Ui::KernelFilterEditor),
    controller(controller_),
    index(index_),
    isClose(false)
{
    ui->setupUi(this);
    if (!inRange(index))
    {
        ui->lblName->setText("Добавление нового фильтра");
        ui->lblMatrixSize->setText(getMatrixLabel(1));
    }
    else {
        ui->lblName->setText("Редактирование фильтра " + controller->getFilters()[index]->getFilterName());
        ui->horizontalSlider->setValue(dynamic_cast<AbstractKernelFilter*>(controller->getFilters()[index])->getKernelSize());
        ui->lblMatrixSize->setText(getMatrixLabel(ui->horizontalSlider->value()));
    }

}

KernelFilterEditor::~KernelFilterEditor()
{
    delete ui;
}

bool KernelFilterEditor::isClosed() const
{
    return this->isClose;
}

ImageController *KernelFilterEditor::getController() const
{
    return this->controller;
}

bool KernelFilterEditor::inRange(int i) const
{
    return (0 <= i && i < controller->getFilters().size());
}

bool KernelFilterEditor::isDeclaratedName(const QString &name) const
{
//    return std::find_if(controller->getFilters().begin(), controller->getFilters().end(),
//                        [&name](AbstractFilter *obj)
//                        {return obj->getFilterName() == name;})
//    != controller->getFilters().end();
    return false;
}

QString KernelFilterEditor::getMatrixLabel(int size) const
{
    std::string tSize = std::to_string(size * 2 + 1);
    return QString::fromStdString(std::string("Матрица ") + tSize + "x" + tSize);
}

void KernelFilterEditor::addFilterFromFactory()
{
    AbstractFilter *filter = nullptr;
    QString name = ui->lineEdit->text();
    if (name.isEmpty())
        throw std::runtime_error("Название фильтра не может быть пустым!");
    if (isDeclaratedName(name))
        throw std::runtime_error("Фильтр" + std::string(name.toLocal8Bit().constData()) + "уже существует!");
    switch (ui->comboBox->currentIndex()) {
    case 0: filter = new GaussianBlur(name, ui->horizontalSlider->value()); break;
    case 1: filter = new MedianBlur(name, ui->horizontalSlider->value()); break;
    }
    if (inRange(index))
    {
        delete controller->getFilters()[index];
        controller->getFilters()[index] = filter;
    }
    else controller->getFilters().push_back(filter);
}

void KernelFilterEditor::on_btnCancel_clicked()
{
    this->isClose = true;
    this->close();
}

void KernelFilterEditor::on_btnOk_clicked()
{
    try {
        addFilterFromFactory();
    } catch (const std::runtime_error &ex) {
        QMessageBox::critical(this, "Ошибка", QString::fromStdString(ex.what()));
        ui->lineEdit->setText("");
        return;
    }
    this->isClose = true;
    this->close();
}


void KernelFilterEditor::on_horizontalSlider_valueChanged(int value)
{
    ui->lblMatrixSize->setText(getMatrixLabel(ui->horizontalSlider->value()));
}

void KernelFilterEditor::on_horizontalSlider_sliderReleased()
{
    ui->lblMatrixSize->setText(getMatrixLabel(ui->horizontalSlider->value()));
}
