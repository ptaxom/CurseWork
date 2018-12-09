#ifndef WRITERSETTINGS_H
#define WRITERSETTINGS_H

#include "mediawriter.h"
#include <QDialog>
#include <string>

namespace Ui {
class writerSettings;
}

class writerSettings : public QDialog
{
    Q_OBJECT

public:
    explicit writerSettings(QWidget *parent = nullptr);
    ~writerSettings();

    void initSettings(MediaWriter *settings_);

private slots:
    void on_btnConfirm_clicked();

    void on_btnCancel_clicked();

    void on_btnChangePath_clicked();

private:
    Ui::writerSettings *ui;
    MediaWriter *settings;

    std::string path;

};

#endif // WRITERSETTINGS_H
