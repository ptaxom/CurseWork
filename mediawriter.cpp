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
    std::string p = path+"//"+getMediaName()+".avi";
    if (usePreferredFPS)
        fps = this->preferredFPS;
    this->writer = new cv::VideoWriter(p, CV_FOURCC('M','J','P','G'), fps, size, true);
}

void MediaWriter::addFrame(const cv::Mat &frame)
{
    if (this->writer == nullptr)
        throw std::runtime_error("You must start recording!");
    cv::Mat frameToWrite;
    cv::cvtColor(frame, frameToWrite, CV_BGR2RGB);
    this->writer->write(frameToWrite);
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
    std::string p = path + "//" + getMediaName() + ".jpg";
    std::cout << p << std::endl;
    p = "1.jpg";
    cv::Mat frameToWrite;
    cv::cvtColor(frame, frameToWrite, CV_BGR2RGB);
    cv::imwrite(p, frameToWrite);
}

bool MediaWriter::isRecordingVideo() const
{
    return this->writer != nullptr;
}

int MediaWriter::getPreferredFPS() const
{
    return this->preferredFPS;
}

bool MediaWriter::getUsePreferredFPS() const
{
    return this->usePreferredFPS;
}

std::string MediaWriter::getPath() const
{
    return this->path;
}

void MediaWriter::setPreferredFPS(int fps)
{
    this->preferredFPS = fps;
}

void MediaWriter::setUsePreferredFPS(bool use)
{
    this->usePreferredFPS = use;
}

void MediaWriter::setPath(std::string path_)
{
    this->path = path_;
}

std::string MediaWriter::getMediaName() const
{
    time_t t;
    time(&t);
    return QDateTime::currentDateTime().toString(Qt::ISODate).toLocal8Bit().constData() + std::string("_") + std::to_string(t % 1000);
}
