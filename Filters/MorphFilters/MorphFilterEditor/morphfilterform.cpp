#include "morphfilterform.h"
#include "ui_morphfilterform.h"

MorphFilterForm::MorphFilterForm(AbstractFilter *filter, std::vector<QString> names, QWidget *parent) :
    AbstractFilterEditor (filter, names, parent),
    ui(new Ui::MorphFilterForm)
{
    ui->setupUi(this);

    for(const auto &val : AbstractMorphFilter::filterNames)
        ui->cmbFilterType->addItem(val.second);
    for(const auto &val : AbstractMorphFilter::kernelNames)
        ui->cmbKernelType->addItem(val.second);

    this->resetFields();

}

MorphFilterForm::~MorphFilterForm()
{
    delete ui;
}

void MorphFilterForm::on_btnCancel_clicked()
{
    this->isClose = true;
    this->close();
}

void MorphFilterForm::on_btnOk_clicked()
{
    try {
       this->HandleOkButton();
    } catch (const std::exception &ex) {
        return;
    }
    this->isClose = true;
    this->close();
}

void MorphFilterForm::resetFields()
{
    if (filter == nullptr)
    {
        ui->lblTitle->setText("Добавление нового фильтра");
        ui->lblMatrixSize->setText(getMatrixLabel(1));
    }
    else {
        ui->lblTitle->setText("Редактирование фильтра " + filter->getFilterName());
        ui->lnedFilterName->setText(filter->getFilterName());

        AbstractMorphFilter *f = dynamic_cast<AbstractMorphFilter*>(filter);

        ui->cmbFilterType->setCurrentIndex(filter->getIndex());
        ui->cmbKernelType->setCurrentIndex(f->getKernelType());

        ui->hslKernelSize->setValue(f->getKernelSize() );
        ui->lblMatrixSize->setText(getMatrixLabel(ui->hslKernelSize->value()));
    }
}

AbstractFilter *MorphFilterForm::getFilterFromFactory()
{
    AbstractFilter* changedFilter = nullptr;
    QString name = ui->lnedFilterName->text();

    checkNameCorrectness(name);

    int kernelSize = ui->hslKernelSize->value();
    int kernelType = ui->cmbKernelType->currentIndex();

    switch (ui->cmbFilterType->currentIndex()) {
    case 0: changedFilter =  new MorphDilate(name, kernelSize, kernelType); break;
    case 1: changedFilter =  new MorphErode(name, kernelSize, kernelType); break;
    case 2: changedFilter =  new MorphClose(name, kernelSize, kernelType); break;
    case 3: changedFilter =  new MorphOpen(name, kernelSize, kernelType); break;
    }
    return changedFilter;
}

void MorphFilterForm::on_hslKernelSize_sliderReleased()
{
    ui->lblMatrixSize->setText(getMatrixLabel(ui->hslKernelSize->value()));
}

void MorphFilterForm::on_hslKernelSize_valueChanged(int value)
{
    ui->lblMatrixSize->setText(getMatrixLabel(ui->hslKernelSize->value()));
}
