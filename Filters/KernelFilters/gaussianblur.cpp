#include "gaussianblur.h"


GaussianBlur::GaussianBlur(int kernelSize) : AbstractKernelFilter ("Размытие Гаусса", kernelSize)
{

}

void GaussianBlur::Process(cv::Mat &image)
{
    cv::GaussianBlur(image, image, cv::Point(this->kernel_size * 2 + 1, this->kernel_size * 2 + 1), 0, 0);
}
