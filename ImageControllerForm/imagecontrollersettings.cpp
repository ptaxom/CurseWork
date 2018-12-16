#include "imagecontrollersettings.h"
#include "ui_imagecontrollersettings.h"

ImageControllerSettings::ImageControllerSettings(ImageController *ctrl, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageControllerSettings)
{
    this->controller = ctrl;
    this->bufferController = *this->controller;
    ui->setupUi(this);
    this->fillListView();
}



ImageControllerSettings::~ImageControllerSettings()
{
    delete ui;
}

void ImageControllerSettings::fillListView()
{
    ui->listFilters->clear();
    for(auto obj : bufferController.getFilters())
        ui->listFilters->addItem(obj->getFilterName());
}

#include <QMessageBox>

