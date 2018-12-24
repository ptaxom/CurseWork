#ifndef CAMERASOURCE_H
#define CAMERASOURCE_H


#include <opencv2/highgui.hpp>

class CameraSource
{
public:
    CameraSource(int id = 0);

    ~CameraSource();

    bool isOpened() const;

    cv::Mat grabCVIMage();

    cv::Mat getLastFrame() const;
    cv::Size getCaptureSize() const;



private:
    int id;
    cv::VideoCapture videoCapture;
    cv::Mat lastFrame;

};

#endif // CAMERASOURCE_H
