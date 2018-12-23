#ifndef APPLICATIONPROCESSOR_H
#define APPLICATIONPROCESSOR_H

#include "../camerasource.h"
#include "../mediawriter.h"
#include "../imagecontroller.h"

#include <QImage>
#include <QPixmap>

#include <opencv2/core.hpp>

class ApplicationProcessor
{
public:
    ApplicationProcessor();

    QPixmap getNextFrame(int width, int height);

    double getFPS() const;

    MediaWriter& getWriter();
    ImageController& getController();
    CameraSource& getCamera();

private:
    CameraSource cSourse;
    MediaWriter writer;
    ImageController controller;


    double frameCaptureTime = 0;
    int framesCount = 0;

    QImage convertFromMatToQImage(cv::Mat &image);

};

#endif // APPLICATIONPROCESSOR_H
