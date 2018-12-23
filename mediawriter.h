#ifndef MEDIAWRITER_H
#define MEDIAWRITER_H

#include <string>
#include <camerasource.h>
#include <time.h>
#include <QDateTime>
#include <opencv2/opencv.hpp>
#include "opencv2/videoio.hpp"

namespace Writer {
    const std::string defaultPath = "";
}


class MediaWriter
{

public:
    MediaWriter(std::string path = Writer::defaultPath);
    ~MediaWriter();

    void startCapture(int fps,const cv::Size &size);
    void addFrame(const cv::Mat &frame);
    void endCapture();

    void ReleaseVideoCapture();

    void makePhoto(const cv::Mat &frame);

    bool isRecordingVideo() const;
    bool isRecordProcessedImage() const;

    int getPreferredFPS() const;
    bool getUsePreferredFPS() const;
    std::string getPath() const;

    void setPreferredFPS(int fps);
    void setUsePreferredFPS(bool use);
    void setPath(std::string path);
    void setRecordProcessedImage(bool record);



private:

    std::string path;
    cv::VideoWriter *writer = nullptr;

    std::string getMediaName() const;

    bool recordProcessedImage;

    bool usePreferredFPS = false;
    int preferredFPS = 30;

    double lastCapture;
    double spf; // seconds per frame

};

#endif // MEDIAWRITER_H
