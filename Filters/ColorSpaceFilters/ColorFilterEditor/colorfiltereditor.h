#ifndef COLORFILTEREDITOR_H
#define COLORFILTEREDITOR_H

#include "../../AbstractFilterEditor/abstractfiltereditor.h"

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

private:
    Ui::ColorFilterEditor *ui;

protected:
    void resetFields() override;

    AbstractFilter* getFilterFromFactory() override;

};

#endif // COLORFILTEREDITOR_H
