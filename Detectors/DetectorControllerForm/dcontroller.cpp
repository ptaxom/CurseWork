#include "dcontroller.h"
#include "ui_dcontroller.h"


DController::DController(AbstractFilter *filter, std::vector<QString> names, QWidget *parent) :
    AbstractFilterEditor (filter, names, parent),
    ui(new Ui::DController)
{
    ui->setupUi(this);

    this->resetFields();

}

DController::~DController()
{
    delete ui;
}

void DController::on_btnCancel_clicked()
{
    this->isClose = true;
    this->close();
}


#include <QDebug>

void DController::on_btnOk_clicked()
{
    try {
       this->HandleOkButton();
    } catch (const std::exception &ex) {
        qDebug() << ex.what() << "\n";
        return;
    }
    this->isClose = true;
    this->close();
}

void DController::resetFields()
{
    if (filter == nullptr)
    {
        ctrlBuffer = new AbstractShapeDetector("",ImageController(), ImageController());
        ui->lblTitle->setText("Добавление нового детектора");
    }
    else {
        ui->lblTitle->setText("Редактирование фильтра " + filter->getFilterName());
        ui->lineEdit->setText(filter->getFilterName());
        ui->comboBox->setCurrentIndex(filter->getIndex());
        ctrlBuffer = dynamic_cast<AbstractShapeDetector*>(filter->clone());
    }
}

AbstractFilter *DController::getFilterFromFactory()
{
    AbstractFilter* changedFilter = nullptr;
    QString name = ui->lineEdit->text();

    checkNameCorrectness(name);

    switch (ui->comboBox->currentIndex())
    {
        case 0: changedFilter = new LBPDetector(name,ctrlBuffer->getPreprocessorRef(), ctrlBuffer->getPostprocessorRef()); break;
    }


    return changedFilter;
}

#include "../../ImageControllerForm/imagecontrollersettings.h"

void DController::on_btnPreProc_clicked()
{
    ImageControllerSettings window(&ctrlBuffer->getPreprocessorRef(), QString("Настройка препроцессора"));
    window.exec();
}

void DController::on_btnPostProc_clicked()
{
    ImageControllerSettings window(&ctrlBuffer->getPostprocessorRef(), QString("Настройка постобработчика"));
    window.exec();
}
