#include "kernelfiltereditor.h"
#include "ui_kernelfiltereditor.h"


KernelFilterEditor::KernelFilterEditor(AbstractFilter *filter_, std::vector<QString> names_, QWidget *parent):
    AbstractFilterEditor (filter_, names_, parent),
    ui(new Ui::KernelFilterEditor)
{
    ui->setupUi(this);
    resetFields();
}

KernelFilterEditor::~KernelFilterEditor()
{
    delete ui;
}

AbstractFilter* KernelFilterEditor::getFilterFromFactory()
{
    AbstractFilter* changedFilter = nullptr;
    QString name = ui->lineEdit->text();

    checkNameCorrectness(name);
    int index = ui->horizontalSlider->value();

    switch (ui->comboBox->currentIndex()) {
    case 0: changedFilter =  new GaussianBlur(name, index); break;
    case 1: changedFilter =  new MedianBlur(name, index); break;
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
       this->HandleOkButton();
    } catch (const std::exception &ex) {
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

void KernelFilterEditor::resetFields()
{
    if (filter == nullptr)
    {
        ui->lblName->setText("Добавление нового фильтра");
        ui->lblMatrixSize->setText(getMatrixLabel(1));
    }
    else {
        ui->lblName->setText("Редактирование фильтра " + filter->getFilterName());
        ui->lineEdit->setText(filter->getFilterName());
        ui->comboBox->setCurrentIndex(filter->getIndex());
        ui->horizontalSlider->setValue(
                    dynamic_cast<AbstractKernelFilter*>(filter)
                    ->getKernelSize() );
        ui->lblMatrixSize->setText(getMatrixLabel(ui->horizontalSlider->value()));
    }
}
