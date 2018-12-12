#include "medianblur.h"


MedianBlur::MedianBlur(int kernelSize) : AbstractKernelFilter ("Медианное размытие", kernelSize)
{

}

void MedianBlur::Process(cv::Mat &image)
{
    cv::medianBlur(image, image, this->kernel_size * 2 + 1);
}
