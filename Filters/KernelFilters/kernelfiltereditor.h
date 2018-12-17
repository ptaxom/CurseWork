#ifndef KERNELFILTEREDITOR_H
#define KERNELFILTEREDITOR_H

#include <QDialog>
#include "../../imagecontroller.h"
#include "../abstractkernelfilter.h"

#include "gaussianblur.h"
#include "medianblur.h"


#include <QMessageBox>

namespace Ui {
class KernelFilterEditor;
}

class KernelFilterEditor : public QDialog
{
    Q_OBJECT

public:
    explicit KernelFilterEditor(ImageController *controller, int index, QWidget *parent = nullptr);
    ~KernelFilterEditor();


private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderReleased();

private:
    Ui::KernelFilterEditor *ui;
    ImageController *controller;
    int index;

    bool inRange(int i) const;
    bool isDeclaratedName(const QString &name) const;
    QString getMatrixLabel(int size) const;

    void addFilterFromFactory();
};

#endif // KERNELFILTEREDITOR_H
