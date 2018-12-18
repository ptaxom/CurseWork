#include "gaussianblur.h"




GaussianBlur::GaussianBlur(QString filterName, int kernelSize) : AbstractKernelFilter (filterName)
{
    this->indexInComboBox = 0;
    this->kernel_size = kernelSize;
}

void GaussianBlur::Process(cv::Mat &image)
{
    cv::GaussianBlur(image, image, cv::Point(this->kernel_size * 2 + 1, this->kernel_size * 2 + 1), 0, 0);
}

AbstractFilter *GaussianBlur::clone()
{
    return new GaussianBlur(this->getFilterName(), this->kernel_size);
}
