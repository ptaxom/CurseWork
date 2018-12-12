#include "abstractkernelfilter.h"

AbstractKernelFilter::AbstractKernelFilter(QString filterName, int kernelSize) : AbstractFilter (filterName)
{
    this->kernel_size = kernelSize;
}

void AbstractKernelFilter::Process(cv::Mat &image)
{

}

