#ifndef DCONTROLLER_H
#define DCONTROLLER_H

#include <QDialog>

namespace Ui {
class DController;
}

class DController : public QDialog
{
    Q_OBJECT

public:
    explicit DController(QWidget *parent = nullptr);
    ~DController();

private:
    Ui::DController *ui;
};

#endif // DCONTROLLER_H
