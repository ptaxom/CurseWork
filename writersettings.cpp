#include "writersettings.h"
#include "ui_writersettings.h"
#include <QFileDialog>


writerSettings::writerSettings(MediaWriter *settings_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::writerSettings)
{
    this->settings = settings_;
    this->path = "";
    ui->setupUi(this);
    initSettings();
}

writerSettings::~writerSettings()
{
    delete ui;
}

void writerSettings::initSettings()
{
    if (settings == nullptr)
        throw std::runtime_error("exception from mediawriter settings");
    this->settings = settings;
    ui->spbPrefferedFPS->setRange(10, 45);
    ui->spbPrefferedFPS->setValue(settings->getPreferredFPS());
    ui->cbUsePreferredFPS->setChecked(settings->getUsePreferredFPS());
    ui->cbRecordProcessedImage->setChecked(settings->isRecordProcessedImage());
}

void writerSettings::on_btnConfirm_clicked()
{
    settings->setPreferredFPS(ui->spbPrefferedFPS->value());
    settings->setUsePreferredFPS(ui->cbUsePreferredFPS->checkState() == Qt::Checked);
    settings->setRecordProcessedImage(ui->cbRecordProcessedImage->checkState() == Qt::Checked);
    if (!path.empty())
        settings->setPath(path+"/");
    this->close();
}

void writerSettings::on_btnCancel_clicked()
{
    this->close();
}

void writerSettings::on_btnChangePath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,"Выберите директорию", QString::fromStdString(settings->getPath()));
    this->path = path.toLocal8Bit().data();
}
