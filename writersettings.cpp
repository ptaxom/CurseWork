#include "writersettings.h"
#include "ui_writersettings.h"
#include <QFileDialog>


writerSettings::writerSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::writerSettings)
{
    this->settings = nullptr;
    this->path = "";
    ui->setupUi(this);
}

writerSettings::~writerSettings()
{
    delete ui;
}

void writerSettings::initSettings(MediaWriter *settings_)
{
    if (settings_ == nullptr)
        throw std::runtime_error("ex");
    this->settings = settings_;
    ui->spbPrefferedFPS->setRange(15, 45);
    ui->spbPrefferedFPS->setValue(settings->getPreferredFPS());
    ui->cbUsePreferredFPS->setChecked(settings->getUsePreferredFPS());
}

void writerSettings::on_btnConfirm_clicked()
{
    settings->setPreferredFPS(ui->spbPrefferedFPS->value());
    settings->setUsePreferredFPS(ui->cbUsePreferredFPS->checkState() == Qt::Checked);
    if (!path.empty())
        settings->setPath(path);
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
    std::cout << this->path;
}
