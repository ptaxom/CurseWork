#ifndef KERNELFILTEREDITOR_H
#define KERNELFILTEREDITOR_H


#include "../abstractkernelfilter.h"
#include "../AbstractFilterEditor/abstractfiltereditor.h"


#include "gaussianblur.h"
#include "medianblur.h"


#include <QMessageBox>


namespace Ui {
class KernelFilterEditor;
}

class KernelFilterEditor : public AbstractFilterEditor
{
    Q_OBJECT

public:
    explicit KernelFilterEditor(AbstractFilter *filter, std::vector<QString> names, QWidget *parent = nullptr);
    ~KernelFilterEditor();


private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderReleased();

private:
    Ui::KernelFilterEditor *ui;

protected:
    AbstractFilter* getFilterFromFactory() override;

    void resetFields() override;


};

#endif // KERNELFILTEREDITOR_H
