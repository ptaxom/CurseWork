#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "writersettings.h"

#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->cSourse = CameraSource(0);
    this->writer = MediaWriter("");


    labelThread = new QTimer(this);
    connect(labelThread, SIGNAL(timeout()), this, SLOT(UpdateLabelImage()));
    labelThread->start(15);


}

MainWindow::~MainWindow()
{
    if (this->writer.isRecordingVideo())
        this->writer.endCapture();
    delete ui;
}


void MainWindow::UpdateLabelImage()
{
    time_t start, end;
    time(&start);

    cv::Mat frame = cSourse.grabCVIMage();

    if (this->writer.isRecordingVideo())
    {
        this->writer.addFrame(frame);
        cv::circle(frame,cv::Point(30,30),10,cv::Scalar(0,0,255),-1);
    }

    QImage img = convertFromMatToQImage(frame);

    QPixmap pix = QPixmap::fromImage(img);

    int w = ui->label->width();
    int h = ui->label->height();

    ui->label->setPixmap(pix.scaled(w,h));

    time(&end);

    frameCaptureTimes += end - start;
    ++framesCount;

    double fps = 1.0 / ((double)frameCaptureTimes / (double)framesCount);

    this->fps = (int)fps;

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



int MainWindow::checkFPS()
{
    if (this->fps > 45)
        this->fps = 45;
    if (this->fps < 15)
        this->fps = 15;
    return this->fps;
}


void MainWindow::on_actVideo_triggered()
{
    try {
        if (!this->writer.isRecordingVideo() && ui->actVideo->text() == "Начать запись видео")
        {
            this->writer.startCapture(checkFPS(),this->cSourse.getCaptureSize());
            ui->actVideo->setText("Остановить запись видео");
            return;
        }
        if (this->writer.isRecordingVideo() && ui->actVideo->text() == "Остановить запись видео")
        {
            this->writer.endCapture();
            ui->actVideo->setText("Начать запись видео");
            return;
        }
        throw std::runtime_error("Unknown error...");
    } catch (const std::runtime_error &ex) {
        this->writer.ReleaseVideoCapture();
        QMessageBox::critical(this,"Ошибка видео", ex.what());
    }
}

void MainWindow::on_actPhoto_triggered()
{
    this->writer.makePhoto(this->cSourse.getLastFrame());
}

void MainWindow::on_actWriterSettings_triggered()
{
    writerSettings window;
    window.initSettings(&this->writer);
    window.setModal(true);
    window.exec();
}

