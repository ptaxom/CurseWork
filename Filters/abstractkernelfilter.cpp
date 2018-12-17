#include "abstractkernelfilter.h"



AbstractKernelFilter::AbstractKernelFilter(QString filterName, QString filterType, int kernelSize) : AbstractFilter (filterName, filterType)
{
    this->kernel_size = kernelSize;
}

int AbstractKernelFilter::getKernelSize() const
{
    return this->kernel_size;
}

