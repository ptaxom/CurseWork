#ifndef IMAGECONTROLLERSETTINGS_H
#define IMAGECONTROLLERSETTINGS_H

#include <QDialog>
#include "../imagecontroller.h"
#include "../Filters/KernelFilters/kernelfiltereditor.h"

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
private slots:
    void on_btnAdd_clicked();


    void on_btnAccept_clicked();

private:
    Ui::ImageControllerSettings *ui;
    ImageController *controller;
    ImageController bufferController;


};

#endif // IMAGECONTROLLERSETTINGS_H
