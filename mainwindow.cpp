#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "writersettings.h"

#include <QtCore>


#include "Detectors/LBPDetector/lbpdetector.h"
#include "Filters/ColorSpaceFilters/weightedcolorchannelfilter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    processor = ApplicationProcessor();

    labelThread = new QTimer(this);
    connect(labelThread, SIGNAL(timeout()), this, SLOT(UpdateLabelImage()));
    labelThread->start(15);


}

MainWindow::~MainWindow()
{
    if (processor.getWriter().isRecordingVideo())
        this->processor.getWriter().endCapture();
    delete ui;
}


void MainWindow::UpdateLabelImage()
{

    int w = ui->label->width();
    int h = ui->label->height();

    ui->label->setPixmap(processor.getNextFrame(w,h));

    QString fpsBar = "FPS: " + QString::number(processor.getFPS());
    ui->statusBar->showMessage(fpsBar);

}



void MainWindow::on_actVideo_triggered()
{
    try {
        if (!processor.getWriter().isRecordingVideo() && ui->actVideo->text() == "Начать запись видео")
        {
            processor.getWriter().startCapture(processor.getFPS(),processor.getCamera().getCaptureSize());
            ui->actVideo->setText("Остановить запись видео");
            return;
        }
        if (processor.getWriter().isRecordingVideo() && ui->actVideo->text() == "Остановить запись видео")
        {
            processor.getWriter().endCapture();
            ui->actVideo->setText("Начать запись видео");
            return;
        }
        throw std::runtime_error("Unknown error...");
    } catch (const std::runtime_error &ex) {
        processor.getWriter().ReleaseVideoCapture();
        QMessageBox::critical(this,"Ошибка видеозаписи", ex.what());
    }
}

void MainWindow::on_actPhoto_triggered()
{
    cv::Mat lastFrame = processor.getCamera().getLastFrame();
    if (processor.getWriter().isRecordProcessedImage())
    {
        cv::Mat buffer;
        lastFrame.copyTo(buffer);
        processor.getController().ApplyFilters(buffer);
        processor.getWriter().makePhoto(buffer);
    }
    else processor.getWriter().makePhoto(lastFrame);
}

void MainWindow::on_actWriterSettings_triggered()
{
    writerSettings window;
    window.initSettings(&processor.getWriter());
    window.exec();
}


void MainWindow::on_actFilterSettings_triggered()
{
    ImageControllerSettings window(&processor.getController(), QString("Настройка фильтров"));
    window.exec();
}
