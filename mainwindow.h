#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <time.h>

#include "camerasource.h"
#include "imagecontroller.h"
#include "mediawriter.h"
#include "facedetector.h"
#include "ImageControllerForm/imagecontrollersettings.h"

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

    QImage convertFromMatToQImage(cv::Mat &image);
    int checkFPS();

    CameraSource cSourse;
    MediaWriter writer;
    ImageController controller;

    Detector::FaceDetector detector;

    double frameCaptureTimes = 0;
    int framesCount = 0;
    int fps = 30;

};

#endif // MAINWINDOW_H
