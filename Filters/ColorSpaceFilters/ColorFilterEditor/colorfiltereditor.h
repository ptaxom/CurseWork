#ifndef COLORFILTEREDITOR_H
#define COLORFILTEREDITOR_H

#include "../../AbstractFilterEditor/abstractfiltereditor.h"

#include "../grayscalefilter.h"
#include "../sepiafilter.h"
#include "../negativefilter.h"
#include "../weightedcolorchannelfilter.h"

#include <cmath>

namespace Ui {
class ColorFilterEditor;
}

class ColorFilterEditor : public AbstractFilterEditor
{
    Q_OBJECT

public:
    explicit ColorFilterEditor(AbstractFilter *filter, std::vector<QString> names, QWidget *parent = nullptr);

    ~ColorFilterEditor();

private slots:

    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void on_hslR_valueChanged(int value);

    void on_hslG_valueChanged(int value);

    void on_hslB_valueChanged(int value);

    void on_hslR_sliderReleased();

    void on_hslG_sliderReleased();

    void on_hslB_sliderReleased();

private:
    Ui::ColorFilterEditor *ui;

    double getDecodedValue(int val) const;
    int getEncodedValue(double val) const;

    QString ColorFilterEditor::getFormattedDescription(QString color,QString var, double val) const;

protected:
    void resetFields() override;

    AbstractFilter* getFilterFromFactory() override;


};

#endif // COLORFILTEREDITOR_H
