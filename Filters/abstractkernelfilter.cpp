#include "abstractkernelfilter.h"



AbstractKernelFilter::AbstractKernelFilter(QString filterName, QString filterType, int kernelSize) : AbstractFilter (filterName, filterType)
{
    this->kernel_size = kernelSize;
}

void AbstractKernelFilter::Process(cv::Mat &image)
{

}

