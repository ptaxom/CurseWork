#include "mediawriter.h"


MediaWriter::MediaWriter(std::string path)
{
    this->path = path;
    this->writer = nullptr;
    this->lastCapture = (double)cv::getTickCount();
    this->spf = 1.0 / (double)this->preferredFPS;
}

MediaWriter::~MediaWriter()
{
    if (this->isRecordingVideo())
        this->endCapture();
    this->ReleaseVideoCapture();
}

void MediaWriter::startCapture(int fps, const cv::Size &size)
{
    if (this->writer != nullptr)
        throw std::runtime_error("You cann't record more than one media!");
    std::string p = path  + getMediaName() + ".avi";
    if (usePreferredFPS)
        fps = this->preferredFPS;
    this->spf = 1 / (double)fps;
    this->lastCapture = (double)cv::getTickCount();
    this->writer = new cv::VideoWriter(p, CV_FOURCC('M','J','P','G'), fps-5, size, true);
}

#include <algorithm>

void MediaWriter::addFrame(const cv::Mat &frame)
{
    if (this->writer == nullptr)
        throw std::runtime_error("You must start recording!");
    double t2 = (double)cv::getTickCount();
    double timeFromLastFrame = (t2 - this->lastCapture) / cv::getTickFrequency();
    if (timeFromLastFrame >= this->spf)
    {
        this->lastCapture = t2;
        cv::Mat frameToWrite;
        cv::cvtColor(frame, frameToWrite, CV_BGR2RGB);
        for(int i = 0; i < frameToWrite.rows; i++)
            for(int j = 0; j < frameToWrite.cols; j++)
            {
                std::swap(frameToWrite.at<cv::Vec3b>(i,j)[0],
                        frameToWrite.at<cv::Vec3b>(i,j)[2]);
            }

        this->writer->write(frameToWrite);
    }
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



void MediaWriter::makePhoto(const cv::Mat &frame)
{
    std::string p = path  + getMediaName() + ".jpg";
    cv::Mat frameToWrite;
    cv::cvtColor(frame, frameToWrite, CV_BGR2RGB);
    cv::imwrite(p, frameToWrite);
}

bool MediaWriter::isRecordingVideo() const
{
    return this->writer != nullptr;
}

bool MediaWriter::isRecordProcessedImage() const
{
    return this->recordProcessedImage;
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

void MediaWriter::setRecordProcessedImage(bool record)
{
    this->recordProcessedImage = record;
}

std::string MediaWriter::getMediaName() const
{
    time_t t;
    time(&t);
    //return QDateTime::currentDateTime().toString(Qt::ISODate).toLocal8Bit().constData() + std::string("_") + std::to_string(t % 1000);
    return std::to_string(t);
}
