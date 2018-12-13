#include "kernelfiltereditor.h"
#include "ui_kernelfiltereditor.h"

KernelFilterEditor::KernelFilterEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KernelFilterEditor)
{
    ui->setupUi(this);
}

KernelFilterEditor::~KernelFilterEditor()
{
    delete ui;
}

void KernelFilterEditor::initFilter(AbstractKernelFilter *filter)
{
    this->filter = filter;
}
