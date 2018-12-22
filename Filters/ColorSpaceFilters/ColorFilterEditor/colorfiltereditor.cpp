#include "colorfiltereditor.h"
#include "ui_colorfiltereditor.h"

ColorFilterEditor::ColorFilterEditor(AbstractFilter *filter, std::vector<QString> names, QWidget *parent) :
    AbstractFilterEditor (filter, names, parent),
    ui(new Ui::ColorFilterEditor)
{
    ui->setupUi(this);

     this->resetFields();

}

ColorFilterEditor::~ColorFilterEditor()
{
    delete ui;
}

void ColorFilterEditor::resetFields()
{
    if (filter == nullptr)
    {
        ui->lblTitle->setText("Добавление нового фильтра");
    }
    else {

    }
}

AbstractFilter *ColorFilterEditor::getFilterFromFactory()
{
    return nullptr;
}

void ColorFilterEditor::on_btnCancel_clicked()
{
    this->isClose = true;
    this->close();
}

void ColorFilterEditor::on_btnOk_clicked()
{
    try {
       this->HandleOkButton();
    } catch (const std::exception &ex) {
        return;
    }
    this->isClose = true;
    this->close();
}

