#include "mediawriter.h"


MediaWriter::MediaWriter(std::string path)
{
    this->path = path;
    this->writer = nullptr;
}

void MediaWriter::startCapture(int fps, const cv::Size &size)
{
    if (this->writer != nullptr)
        throw std::runtime_error("You cann't record more than one media!");
    std::string p = path+"/"+getMediaName()+".avi";
    this->writer = new cv::VideoWriter("1.avi", CV_FOURCC('M','J','P','G'), fps, size, true);
}

void MediaWriter::addFrame(const cv::Mat &frame)
{
    if (this->writer == nullptr)
        throw std::runtime_error("You must start recording!");
    this->writer->write(frame);
}

void MediaWriter::endCapture()
{
    if (this->writer == nullptr)
        throw std::runtime_error("You must start recording!");
    this->writer->release();
    delete this->writer;
    this->writer = nullptr;
}

void MediaWriter::ReleaseVideoCapture()
{
    if (this->writer != nullptr)
    {
        this->writer->release();
        delete this->writer;
        this->writer = nullptr;
    }
}


#include <iostream>
#include <time.h>
void MediaWriter::makePhoto(const cv::Mat &frame)
{
    std::string p = path + "/" + getMediaName() + ".jpg";
    cv::imwrite(p, frame);
}

bool MediaWriter::isRecordingVideo() const
{
    return this->writer != nullptr;
}

std::string MediaWriter::getMediaName() const
{
    time_t t;
    time(&t);
    return QDateTime::currentDateTime().toString(Qt::ISODate).toLocal8Bit().constData() + std::to_string(t % 1000) + std::string("_");
}
