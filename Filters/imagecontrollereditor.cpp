#include "imagecontrollereditor.h"
#include "ui_imagecontrollereditor.h"

ImageControllerEditor::ImageControllerEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageControllerEditor)
{
    ui->setupUi(this);
}

ImageControllerEditor::~ImageControllerEditor()
{
    delete ui;
}
