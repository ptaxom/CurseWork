#include "imagecontroller.h"

#include "Filters/KernelFilters/gaussianblur.h"
#include "Filters/KernelFilters/medianblur.h"

ImageController::ImageController()
{
    this->filters.push_back(new GaussianBlur("Filter 1", 2));
    this->filters.push_back(new MedianBlur("Filter 2", 3));
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
