#ifndef IMAGECONTROLLEREDITOR_H
#define IMAGECONTROLLEREDITOR_H

#include <QDialog>

namespace Ui {
class ImageControllerEditor;
}

class ImageControllerEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ImageControllerEditor(QWidget *parent = nullptr);
    ~ImageControllerEditor();

private:
    Ui::ImageControllerEditor *ui;
};

#endif // IMAGECONTROLLEREDITOR_H
