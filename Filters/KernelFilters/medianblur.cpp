#include "medianblur.h"



MedianBlur::MedianBlur(QString filterName, int kernelSize) : AbstractKernelFilter (filterName)
{
    this->kernel_size = kernelSize;
    this->indexInComboBox = 1;
}

void MedianBlur::Process(cv::Mat &image)
{
    cv::medianBlur(image, image, this->kernel_size * 2 + 1);
}

AbstractFilter *MedianBlur::clone()
{
    return new MedianBlur(this->getFilterName(), this->kernel_size);
}
