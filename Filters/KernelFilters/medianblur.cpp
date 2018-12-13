#include "medianblur.h"



MedianBlur::MedianBlur(QString filterName, int kernelSize) : AbstractKernelFilter (filterName, "MedianBlur")
{
    this->kernel_size = kernelSize;
}

void MedianBlur::Process(cv::Mat &image)
{
    cv::medianBlur(image, image, this->kernel_size * 2 + 1);
}
