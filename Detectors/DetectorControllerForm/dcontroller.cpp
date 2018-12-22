#include "dcontroller.h"
#include "ui_dcontroller.h"

DController::DController(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DController)
{
    ui->setupUi(this);
}

DController::~DController()
{
    delete ui;
}
