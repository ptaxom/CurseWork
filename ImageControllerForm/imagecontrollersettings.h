#ifndef IMAGECONTROLLERSETTINGS_H
#define IMAGECONTROLLERSETTINGS_H

#include <QDialog>
#include "../imagecontroller.h"

#include "../Filters/KernelFilters/kernelfiltereditor.h"
#include "../Filters/MorphFilters/MorphFilterEditor/morphfilterform.h"
#include "../Filters/ColorSpaceFilters/ColorFilterEditor/colorfiltereditor.h"
#include "../Detectors/DetectorControllerForm/dcontroller.h"

namespace Ui {
class ImageControllerSettings;
}

class ImageControllerSettings : public QDialog
{
    Q_OBJECT

public:
    explicit ImageControllerSettings(ImageController *ctrl,QString wndTitle, QWidget *parent = nullptr);
    ~ImageControllerSettings();


private slots:
    void on_btnAdd_clicked();

    void on_btnAccept_clicked();

    void on_btnDelete_clicked();

    void on_listFilters_doubleClicked(const QModelIndex &index);

private:
    Ui::ImageControllerSettings *ui;
    ImageController *controller;
    ImageController bufferController;

    template<class T>
    AbstractFilter *genericFilterFactory(AbstractFilter *filter = nullptr);

    void fillListView();

    std::vector<QString> getDeclaratedNames() const;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

};

#endif // IMAGECONTROLLERSETTINGS_H
