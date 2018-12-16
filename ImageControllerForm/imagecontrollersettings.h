#ifndef IMAGECONTROLLERSETTINGS_H
#define IMAGECONTROLLERSETTINGS_H

#include <QDialog>
#include "../imagecontroller.h"

namespace Ui {
class ImageControllerSettings;
}

class ImageControllerSettings : public QDialog
{
    Q_OBJECT

public:
    explicit ImageControllerSettings(ImageController *ctrl, QWidget *parent = nullptr);
    ~ImageControllerSettings();

    void fillListView();
private:
    Ui::ImageControllerSettings *ui;
    ImageController *controller;
    ImageController bufferController;
};

#endif // IMAGECONTROLLERSETTINGS_H
