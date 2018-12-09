#ifndef MEDIAWRITER_H
#define MEDIAWRITER_H

#include <string>
#include <camerasource.h>
#include <QDateTime>
#include <opencv2/opencv.hpp>

namespace Writer {
    const std::string defaultPath = "C:/CurseWorkSavedImages";
}


class MediaWriter
{

public:
    MediaWriter(std::string path = Writer::defaultPath);

    void startCapture(int fps,const cv::Size &size);
    void addFrame(const cv::Mat &frame);
    void endCapture();

    void ReleaseVideoCapture();

    void makePhoto(const cv::Mat &frame);

    bool isRecordingVideo() const;

private:

    std::string path;
    cv::VideoWriter *writer = nullptr;

    std::string getMediaName() const;

};

#endif // MEDIAWRITER_H
