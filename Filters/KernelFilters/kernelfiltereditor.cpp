#include "kernelfiltereditor.h"
#include "ui_kernelfiltereditor.h"


KernelFilterEditor::KernelFilterEditor(AbstractFilter *filter_, std::vector<QString> names_, QWidget *parent):
    QDialog(parent),
    ui(new Ui::KernelFilterEditor),
    filter(filter_),
    names(names_),
    isClose(false)
{
    ui->setupUi(this);
    if (filter == nullptr)
    {
        ui->lblName->setText("Добавление нового фильтра");
        ui->lblMatrixSize->setText(getMatrixLabel(1));
    }
    else {
        ui->lblName->setText("Редактирование фильтра " + filter->getFilterName());
        ui->horizontalSlider->setValue(
                    dynamic_cast<AbstractKernelFilter*>(filter)
                    ->getKernelSize() );
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

AbstractFilter* KernelFilterEditor::getFilter() const
{
    return this->filter;
}

bool KernelFilterEditor::isDeclaratedName(const QString &name) const
{
    return std::find(names.begin(), names.end(), name) != names.end();
    //return false;
}

QString KernelFilterEditor::getMatrixLabel(int size) const
{
    std::string tSize = std::to_string(size * 2 + 1);
    return QString::fromStdString(std::string("Матрица ") + tSize + "x" + tSize);
}

AbstractFilter* KernelFilterEditor::getFilterFromFactory()
{
    AbstractFilter* changedFilter = nullptr;
    QString name = ui->lineEdit->text();
    if (name.isEmpty())
        throw std::runtime_error("Название фильтра не может быть пустым!");
    if (isDeclaratedName(name) && this->filter == nullptr)
        throw std::runtime_error("Фильтр" + std::string(name.toLocal8Bit().constData()) + "уже существует!");
    if (isDeclaratedName(name) && this->filter != nullptr)
        throw std::runtime_error("Название фильтра не может совпадать с предыдущим");
    switch (ui->comboBox->currentIndex()) {
    case 0: changedFilter =  new GaussianBlur(name, ui->horizontalSlider->value()); break;
    case 1: changedFilter =  new MedianBlur(name, ui->horizontalSlider->value()); break;
    }
    return changedFilter;
}

void KernelFilterEditor::on_btnCancel_clicked()
{
    this->isClose = true;
    this->close();
}

void KernelFilterEditor::on_btnOk_clicked()
{
    try {
        AbstractFilter* newFilter = getFilterFromFactory();
        if (this->filter != nullptr)
            delete this->filter;
        this->filter = newFilter;
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
