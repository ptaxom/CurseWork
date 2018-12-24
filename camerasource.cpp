#include "camerasource.h"

CameraSource::CameraSource(int id)
{
    this->id = id;
    this->videoCapture = cv::VideoCapture(id);
    videoCapture.open(id);
}

CameraSource::~CameraSource()
{
    if(videoCapture.isOpened())
        videoCapture.release();
}

bool CameraSource::isOpened() const
{
    if (!videoCapture.isOpened())
        throw std::runtime_error("Cann't open capture "+std::to_string(id));
    return true;
}

cv::Mat CameraSource::grabCVIMage()
{
    videoCapture.read(this->lastFrame);
    return this->lastFrame;
}

cv::Mat CameraSource::getLastFrame() const
{
    return this->lastFrame;
}

cv::Size CameraSource::getCaptureSize() const
{
    int w = videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);
    int h = videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
    return cv::Size(w,h);
}

