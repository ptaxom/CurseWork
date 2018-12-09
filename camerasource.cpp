#include "camerasource.h"

CameraSource::CameraSource()
{
}

CameraSource::CameraSource(int id)
{
    this->id = id;
    this->vCap = cv::VideoCapture(id);
    vCap.open(id);
}

CameraSource::~CameraSource()
{
    if(vCap.isOpened())
        vCap.release();
}

bool CameraSource::isOpened() const
{
    if (!vCap.isOpened())
        throw std::runtime_error("Cann't open capture "+std::to_string(id));
    return true;
}

cv::Mat CameraSource::grabCVIMage()
{
    vCap.read(this->lastFrame);
    return this->lastFrame;
}

cv::Mat CameraSource::getLastFrame() const
{
    return this->lastFrame;
}

cv::Size CameraSource::getCaptureSize() const
{
    int w = vCap.get(CV_CAP_PROP_FRAME_WIDTH);
    int h = vCap.get(CV_CAP_PROP_FRAME_HEIGHT);
    return cv::Size(w,h);
}

