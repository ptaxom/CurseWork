#ifndef MEDIANBLUR_H
#define MEDIANBLUR_H
#include "../abstractkernelfilter.h"

class MedianBlur : public AbstractKernelFilter
{
public:
    MedianBlur(int kernelSize);
    void Process(cv::Mat &image) override;
};

#endif // MEDIANBLUR_H
