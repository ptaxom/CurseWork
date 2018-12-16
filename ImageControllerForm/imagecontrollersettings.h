#ifndef IMAGECONTROLLERSETTINGS_H
#define IMAGECONTROLLERSETTINGS_H

#include <QDialog>

namespace Ui {
class ImageControllerSettings;
}

class ImageControllerSettings : public QDialog
{
    Q_OBJECT

public:
    explicit ImageControllerSettings(QWidget *parent = nullptr);
    ~ImageControllerSettings();

private:
    Ui::ImageControllerSettings *ui;
};

#endif // IMAGECONTROLLERSETTINGS_H
