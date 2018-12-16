#ifndef MEDIANBLUR_H
#define MEDIANBLUR_H
#include "../abstractkernelfilter.h"

class MedianBlur : public AbstractKernelFilter
{
public:
    MedianBlur(QString filterName, int kernelSize = 1);

    void Process(cv::Mat &image) override;
    AbstractFilter* clone() override;
};

#endif // MEDIANBLUR_H
