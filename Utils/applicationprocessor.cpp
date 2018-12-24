#include "applicationprocessor.h"

ApplicationProcessor::ApplicationProcessor()
{
    this->cSourse = CameraSource(0);
    cSourse.isOpened();
    this->writer = MediaWriter();
}


QImage ApplicationProcessor::convertFromMatToQImage(cv::Mat &mat)
{  if(mat.channels() == 1) {
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
    } else if(mat.channels() == 3) {
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    } else {
        throw std::runtime_error("Unknown type of cv::Mat from ApplicationProcessor::convertFromMatToQImage");
    }
    return QImage();

}

#include <QPainter>

QPixmap ApplicationProcessor::getNextFrame(int width, int height)
{
    if (framesCount > 300)
    {
        framesCount = 0;
        frameCaptureTime = 0;
    }
    double start, end;
    start = (double)cv::getTickCount();

    cv::Mat image = cSourse.grabCVIMage();
    cv::Mat frame;
    cv::flip(image, frame,1);

    if (writer.isRecordingVideo() && !writer.isRecordProcessedImage())
        writer.addFrame(frame);

    this->controller.ApplyFilters(frame);

    if (writer.isRecordingVideo() && writer.isRecordProcessedImage())
        writer.addFrame(frame);


    QImage img = convertFromMatToQImage(frame);
    QPixmap pixmap = QPixmap::fromImage(img).scaled(width, height);

    if (writer.isRecordingVideo())
    {
        QPainter pixPaint(&pixmap);
        QBrush brush(Qt::red);
        pixPaint.setBrush(brush);
        pixPaint.drawEllipse(40,40,20,20);
    }

    end = (double)cv::getTickCount();

    frameCaptureTime += (end - start) / cv::getTickFrequency();
    ++framesCount;

    return pixmap;
}

double ApplicationProcessor::getFPS() const
{
    return (double)(framesCount) / frameCaptureTime;
}

MediaWriter &ApplicationProcessor::getWriter()
{
    return writer;
}

ImageController &ApplicationProcessor::getController()
{
    return controller;
}

CameraSource &ApplicationProcessor::getCamera()
{
    return cSourse;
}
