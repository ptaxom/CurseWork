#include "imagecontroller.h"

#include "Filters/KernelFilters/gaussianblur.h"
#include "Filters/KernelFilters/medianblur.h"

ImageController::ImageController()
{
    this->filters.push_back(new GaussianBlur(5));
    this->filters.push_back(new MedianBlur(5));
}

ImageController::~ImageController()
{
    for(auto obj : this->filters)
        delete obj;
}

void ImageController::ApplyFilters(cv::Mat &frame)
{
    for(auto obj : this->filters)
        obj->Process(frame);
}
