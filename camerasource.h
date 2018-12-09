#ifndef CAMERASOURCE_H
#define CAMERASOURCE_H


#include <opencv2/highgui.hpp>

class CameraSource
{
public:
    CameraSource();

    CameraSource(int id);
    ~CameraSource();

    bool isOpened() const;

    cv::Mat grabCVIMage();

    cv::Mat getLastFrame() const;
    cv::Size getCaptureSize() const;



private:
    int id;

    cv::VideoCapture vCap;
    cv::Mat lastFrame;

};

#endif // CAMERASOURCE_H
