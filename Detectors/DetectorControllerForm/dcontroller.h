#ifndef DCONTROLLER_H
#define DCONTROLLER_H


#include "../../Filters/AbstractFilterEditor/abstractfiltereditor.h"

#include "../LBPDetector/lbpdetector.h"


namespace Ui {
class DController;
}

class DController : public AbstractFilterEditor
{
    Q_OBJECT

public:
    explicit DController(AbstractFilter *filter, std::vector<QString> names, QWidget *parent = nullptr);

    ~DController();

private:
    Ui::DController *ui;
    AbstractShapeDetector *ctrlBuffer = nullptr;


protected:

    void resetFields() override;

    AbstractFilter* getFilterFromFactory() override;
private slots:
    void on_btnOk_clicked();
    void on_btnCancel_clicked();

    void on_btnPreProc_clicked();
    void on_btnPostProc_clicked();
};

#endif // DCONTROLLER_H
