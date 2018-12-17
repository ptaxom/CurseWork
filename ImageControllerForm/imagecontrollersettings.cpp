#include "imagecontrollersettings.h"
#include "ui_imagecontrollersettings.h"

ImageControllerSettings::ImageControllerSettings(ImageController *ctrl, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageControllerSettings)
{
    this->controller = ctrl;
    this->bufferController = *this->controller;

    this->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    this->setFocus();

    this->setMouseTracking(true);

    this->installEventFilter(this);
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



void ImageControllerSettings::on_btnAdd_clicked()
{
    if (ui->comboBox->currentIndex() == 0)
    {
        KernelFilterEditor editor(&bufferController, -1);
        editor.setModal(true);
        editor.exec();
        while (!editor.isClosed());
        fillListView();
    }
}

void ImageControllerSettings::on_btnAccept_clicked()
{
    this->controller = &this->bufferController;
    this->close();
}

#include <QDebug>

void ImageControllerSettings::keyPressEvent(QKeyEvent *event)
{
 //   qDebug() << "Key pressed\n";
}

void ImageControllerSettings::mouseMoveEvent(QMouseEvent *event)
{
   // qDebug() << "Mouse moved\n";
    fillListView();
}
