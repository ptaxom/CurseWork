#ifndef MEDIANBLUR_H
#define MEDIANBLUR_H
#include "../abstractkernelfilter.h"

class MedianBlur : public AbstractKernelFilter
{
public:
    MedianBlur(QString filterName, int kernelSize = 1);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;
};

#endif // MEDIANBLUR_H
