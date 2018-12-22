#include "abstractfiltereditor.h"




AbstractFilterEditor::AbstractFilterEditor(AbstractFilter *filter_, std::vector<QString> names_, QWidget *parent) :
    QDialog(parent),
    filter(filter_),
    names(names_),
    isClose(false)
{
    this->setModal(true);
}

bool AbstractFilterEditor::isClosed() const
{
    return this->isClose;
}

AbstractFilter* AbstractFilterEditor::getFilter() const
{
    return this->filter;
}

bool AbstractFilterEditor::isDeclaratedName(const QString &name) const
{
    return std::find(names.begin(), names.end(), name) != names.end();
}

void AbstractFilterEditor::checkNameCorrectness(const QString &name) const
{
    if (name.isEmpty())
        throw std::runtime_error("Название фильтра не может быть пустым!");
    if (isDeclaratedName(name) && this->filter == nullptr)
        throw std::runtime_error("Фильтр " + std::string(name.toLocal8Bit().constData()) + " уже существует!");
}

QString AbstractFilterEditor::getMatrixLabel(int size) const
{
    std::string tSize = std::to_string(size * 2 + 1);
    return QString::fromStdString(std::string("Матрица ") + tSize + "x" + tSize);
}

void AbstractFilterEditor::HandleOkButton()
{
    try {
        AbstractFilter* newFilter = getFilterFromFactory();
        if (this->filter != nullptr)
            delete this->filter;
        this->filter = newFilter;
    } catch (const std::runtime_error &ex) {
        QMessageBox::critical(this, "Ошибка", QString::fromStdString(ex.what()));
        this->resetFields();
        throw std::exception();
    }
    catch(...) {
        throw std::exception();
    }
}


void AbstractFilterEditor::closeEvent(QCloseEvent *event)
{
    this->isClose = true;
}

/*

  Code to Copy-Paste

void ::on_btnCancel_clicked()
{
    this->isClose = true;
    this->close();
}

void ::on_btnOk_clicked()
{
    try {
       this->HandleOkButton();
    } catch (const std::exception &ex) {
        return;
    }
    this->isClose = true;
    this->close();
}

*/
