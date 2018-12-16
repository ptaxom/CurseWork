#ifndef ABSTRACTKERNELFILTER_H
#define ABSTRACTKERNELFILTER_H

#include "abstractfilter.h"

class AbstractKernelFilter : public AbstractFilter
{
public:
    AbstractKernelFilter(QString filterName, QString filterType = "AbstractKernelFilter", int kernelSize = 1);

    virtual void Process(cv::Mat &image) {}
    virtual AbstractFilter* clone() {return nullptr; }

protected:
    int kernel_size;

};

#endif // ABSTRACTKERNELFILTER_H
