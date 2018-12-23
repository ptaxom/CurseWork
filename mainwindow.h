#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>

#include "ImageControllerForm/imagecontrollersettings.h"
#include "Utils/applicationprocessor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public slots:

    void UpdateLabelImage();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actPhoto_triggered();

    void on_actVideo_triggered();

    void on_actWriterSettings_triggered();

    void on_actFilterSettings_triggered();

private:

    Ui::MainWindow *ui;

    QTimer *labelThread;

    ApplicationProcessor processor;


};

#endif // MAINWINDOW_H
