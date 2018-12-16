#include "imagecontrollersettings.h"
#include "ui_imagecontrollersettings.h"

ImageControllerSettings::ImageControllerSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageControllerSettings)
{
    ui->setupUi(this);
}

ImageControllerSettings::~ImageControllerSettings()
{
    delete ui;
}
