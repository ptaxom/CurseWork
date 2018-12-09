#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <time.h>

#include "camerasource.h"
#include "mediawriter.h"

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

private:
    Ui::MainWindow *ui;

    QTimer *labelThread;

    QImage convertFromMatToQImage(cv::Mat &image);
    int checkFPS();

    CameraSource cSourse;
    MediaWriter writer;

    time_t frameCaptureTimes = 0;
    int framesCount = 0;
    int fps = 30;

};

#endif // MAINWINDOW_H
