#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cameraCapture.open(0);


    labelThread = new QTimer(this);
    connect(labelThread, SIGNAL(timeout()), this, SLOT(UpdateLabelImage()));
    labelThread->start(20);


}

MainWindow::~MainWindow()
{
    cameraCapture.release();
    delete ui;
}


void MainWindow::UpdateLabelImage()
{
    time_t start, end;
    time(&start);

    cv::Mat frame;
    cameraCapture.read(frame);

    QImage img = convertFromMatToQImage(frame);

    QPixmap pix = QPixmap::fromImage(img);

    int w = ui->label->width();
    int h = ui->label->height();

    ui->label->setPixmap(pix.scaled(w,h));

    time(&end);

    frameCaptureTimes += end - start;
    framesCount++;

    double fps = 1.0 / ((double)frameCaptureTimes / (double)framesCount);


    std::string fpsBar = "FPS: " + std::to_string(fps);
    //fpsBar = fpsBar.substr(0,std::to_string((int)fps).length()+7);

    if (framesCount % 2 == 1)
        ui->statusBar->showMessage(QString::fromStdString(fpsBar));

}


QImage MainWindow::convertFromMatToQImage(cv::Mat &mat) {
    if(mat.channels() == 1) {
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
    } else if(mat.channels() == 3) {
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    } else {
        qDebug() << "in convertOpenCVMatToQtQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();        // return a blank QImage if the above did not work
}


void MainWindow::on_actVideo_triggered()
{
    if (ui->actVideo->text() == "Начать запись видео")
        ui->actVideo->setText("Остановить запись видео");
    else ui->actVideo->setText("Начать запись видео");
}

void MainWindow::on_actPhoto_triggered()
{

}
