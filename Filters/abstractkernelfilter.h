#ifndef ABSTRACTKERNELFILTER_H
#define ABSTRACTKERNELFILTER_H

#include "abstractfilter.h"

class AbstractKernelFilter : public AbstractFilter
{
public:
    AbstractKernelFilter(QString filterName, QString filterType = "AbstractKernelFilter", int kernelSize = 1);

    virtual void Process(cv::Mat &image);

protected:
    int kernel_size;

};

#endif // ABSTRACTKERNELFILTER_H
