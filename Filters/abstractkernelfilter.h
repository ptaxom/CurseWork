#ifndef ABSTRACTKERNELFILTER_H
#define ABSTRACTKERNELFILTER_H

#include "abstractfilter.h"
#include <map>

class AbstractKernelFilter : public AbstractFilter
{
public:
    AbstractKernelFilter(QString filterName, QString filterType = "AbstractKernelFilter" , int kernelSize = 1);

    virtual void Process(cv::Mat &image) const {}
    virtual AbstractFilter* clone() const {return nullptr; }

    int getKernelSize() const;

protected:
    int kernel_size;
};


#endif // ABSTRACTKERNELFILTER_H
