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
    labelThread->start(1);


}

MainWindow::~MainWindow()
{
    cameraCapture.release();
    delete ui;
}


void MainWindow::UpdateLabelImage()
{
    cv::Mat frame;
    cameraCapture.read(frame);

    QImage img = convertFromMatToQImage(frame);

    QPixmap pix = QPixmap::fromImage(img);

    int w = ui->label->width();
    int h = ui->label->height();

    ui->label->setPixmap(pix.scaled(w,h));
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
