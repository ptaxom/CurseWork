#ifndef KERNELFILTEREDITOR_H
#define KERNELFILTEREDITOR_H

#include <QDialog>
#include "../abstractkernelfilter.h"

namespace Ui {
class KernelFilterEditor;
}

class KernelFilterEditor : public QDialog
{
    Q_OBJECT

public:
    explicit KernelFilterEditor(QWidget *parent = nullptr);
    ~KernelFilterEditor();

    void initFilter(AbstractKernelFilter *filter);

private:
    Ui::KernelFilterEditor *ui;
    AbstractKernelFilter *filter;
};

#endif // KERNELFILTEREDITOR_H
