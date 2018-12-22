#ifndef KERNELFILTEREDITOR_H
#define KERNELFILTEREDITOR_H

#include <QDialog>
#include <memory>
#include "../../imagecontroller.h"
#include "../abstractkernelfilter.h"

#include "gaussianblur.h"
#include "medianblur.h"


#include <QMessageBox>

//using AbstPtr = std::shared_ptr<AbstractFilter>;

namespace Ui {
class KernelFilterEditor;
}

class KernelFilterEditor : public QDialog
{
    Q_OBJECT

public:
    explicit KernelFilterEditor(AbstractFilter *filter, std::vector<QString> names, QWidget *parent = nullptr);
    ~KernelFilterEditor() override;


    bool isClosed() const;
    AbstractFilter* getFilter() const;

private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderReleased();

private:
    Ui::KernelFilterEditor *ui;
    AbstractFilter* filter;
    std::vector<QString> names;

    bool isClose;

    bool isDeclaratedName(const QString &name) const;
    QString getMatrixLabel(int size) const;

    AbstractFilter* getFilterFromFactory();

    void closeEvent(QCloseEvent *event) override;


};

#endif // KERNELFILTEREDITOR_H
