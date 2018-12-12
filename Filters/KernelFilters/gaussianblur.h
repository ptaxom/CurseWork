#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include "../abstractkernelfilter.h"
#include <opencv2/imgproc.hpp>

class GaussianBlur : public AbstractKernelFilter
{
public:
    GaussianBlur(int kernelSize = 1);

    void Process(cv::Mat &image) override;
};

#endif // GAUSSIANBLUR_H
