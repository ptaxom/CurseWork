#ifndef MORPHFILTERFORM_H
#define MORPHFILTERFORM_H

#include <QDialog>

#include "../../AbstractFilterEditor/abstractfiltereditor.h"
#include "../../abstractmorphfilter.h"

#include "../morphclose.h"
#include "../morphopen.h"
#include "../morphdilate.h"
#include "../morpherode.h"

namespace Ui {
class MorphFilterForm;
}

class MorphFilterForm : public AbstractFilterEditor
{
    Q_OBJECT

public:
    explicit MorphFilterForm(AbstractFilter *filter, std::vector<QString> names, QWidget *parent = nullptr);

    ~MorphFilterForm();

private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

    void on_hslKernelSize_sliderReleased();

    void on_hslKernelSize_valueChanged(int value);

private:
    Ui::MorphFilterForm *ui;

public:
    void resetFields() override;

protected:
    AbstractFilter* getFilterFromFactory() override;
};

#endif // MORPHFILTERFORM_H
