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

#include <QDebug>

void ColorFilterEditor::resetFields()
{
    if (filter == nullptr)
    {
        ui->lblTitle->setText("Добавление нового фильтра");

        ui->hslR->setValue(10);
        ui->hslG->setValue(10);
        ui->hslB->setValue(10);

        ui->lblRV->setText(getFormattedDescription("красного","r", getDecodedValue(10)));
        ui->lblGV->setText(getFormattedDescription("зеленого","g", getDecodedValue(10)));
        ui->lblBV->setText(getFormattedDescription("синего","b", getDecodedValue(10)));
    }
    else {
         ui->lblTitle->setText("Редактирование фильтра");
         ui->lineEdit->setText(filter->getFilterName());
         if (filter->getIndex() < 3)
         {
             ui->tabWidget->setTabEnabled(0,true);
             ui->tabWidget->setTabEnabled(1,false);
             ui->comboBox->setCurrentIndex(filter->getIndex());

         }
         else {
             ui->tabWidget->setTabEnabled(1,true);
             ui->tabWidget->setTabEnabled(0,false);
             WeightedColorChannelFilter *wcc = dynamic_cast<WeightedColorChannelFilter*>(filter);

             ui->lblRV->setText(getFormattedDescription("красного", "r", wcc->getR()));
             ui->lblGV->setText(getFormattedDescription("зеленого", "g", wcc->getG()));
             ui->lblBV->setText(getFormattedDescription("синего"  , "b", wcc->getB()));

             ui->hslR->setValue(getEncodedValue(wcc->getR()));
             ui->hslG->setValue(getEncodedValue(wcc->getG()));
             ui->hslB->setValue(getEncodedValue(wcc->getB()));

    }
    }
}

AbstractFilter *ColorFilterEditor::getFilterFromFactory()
{
    AbstractFilter* changedFilter = nullptr;
    QString name = ui->lineEdit->text();

    checkNameCorrectness(name);

    if (ui->tabWidget->currentIndex() == 0)
    {
        switch (ui->comboBox->currentIndex()) {
        case 0: changedFilter =  new NegativeFilter(name); break;
        case 1: changedFilter =  new GrayScaleFilter(name); break;
        }
    }
    else
        changedFilter = new WeightedColorChannelFilter(name, getDecodedValue(ui->hslR->value()),
                                                             getDecodedValue(ui->hslG->value()),
                                                             getDecodedValue(ui->hslB->value()));
    return changedFilter;
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


void ColorFilterEditor::on_hslR_valueChanged(int value)
{
    ui->lblRV->setText(getFormattedDescription("красного","r", getDecodedValue(value)));
}

void ColorFilterEditor::on_hslG_valueChanged(int value)
{
    ui->lblGV->setText(getFormattedDescription("зеленого","g", getDecodedValue(value)));
}

void ColorFilterEditor::on_hslB_valueChanged(int value)
{
    ui->lblBV->setText(getFormattedDescription("синего","b", getDecodedValue(value)));
}

void ColorFilterEditor::on_hslR_sliderReleased()
{
    int value = ui->hslR->value();
    ui->lblRV->setText(getFormattedDescription("красного","r", getDecodedValue(value)));
}

void ColorFilterEditor::on_hslG_sliderReleased()
{
    int value = ui->hslG->value();
    ui->lblGV->setText(getFormattedDescription("зеленого","g", getDecodedValue(value)));
}

void ColorFilterEditor::on_hslB_sliderReleased()
{
    int value = ui->hslB->value();
    ui->lblBV->setText(getFormattedDescription("синего","b", getDecodedValue(value)));
}


double ColorFilterEditor::getDecodedValue(int val) const
{
    if (abs(val) < 10)
        return (double)val/10.0;
    else return (double)(val < 0 ? val + 9 : val - 9);
}

int ColorFilterEditor::getEncodedValue(double val) const
{
    if (abs(val) < 1.0)
        return (int)(val * 10.0);
    else return (int)(val < 0 ? val - 9.0 : val + 9.0);
}

QString ColorFilterEditor::getFormattedDescription(QString color,QString var, double val) const
{
    QString textVal = std::abs(val) < 1.0 ? "0." + QString::number((int)abs(val*10.0)) : QString::number((int)abs(val));
    QString formula;
    if (textVal == "0.0")
        formula = QString("%1 = 0").arg(var);
        else if (abs(val) == 1.0)
            formula = QString("%1 = %2%3").arg(var, val < 0 ? "255-" : "", var);
    else formula = QString("%1 = %2%3%4").arg(var,
                                              val < 0 ? "255-" : "",
                                              textVal, var);
    return QString("Коррекция %1 канала: %2").arg(color,formula);
}
