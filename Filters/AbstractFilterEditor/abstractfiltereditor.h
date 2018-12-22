#ifndef ABSTRACTFILTEREDITOR_H
#define ABSTRACTFILTEREDITOR_H


#include <QDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include "../abstractfilter.h"

class AbstractFilterEditor : public QDialog
{
public:
     explicit AbstractFilterEditor(AbstractFilter *filter, std::vector<QString> names, QWidget *parent = nullptr);

    bool isClosed() const;
    AbstractFilter* getFilter() const;

protected:
    AbstractFilter* filter = nullptr;
    std::vector<QString> names;

    bool isClose;

    bool isDeclaratedName(const QString &name) const;

    void checkNameCorrectness(const QString &name) const;

    QString getMatrixLabel(int size) const;


    void HandleOkButton();

    void closeEvent(QCloseEvent *event) override;

    void keyPressEvent(QKeyEvent *e) override;

protected:
    virtual void resetFields() {}

    virtual AbstractFilter* getFilterFromFactory()
    {
        throw std::exception("Exception from virtual getFiltetFromFactory()");
        return nullptr;
    }


};

#endif // ABSTRACTFILTEREDITOR_H
