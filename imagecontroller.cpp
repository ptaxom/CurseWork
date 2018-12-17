#include "imagecontroller.h"

#include "Filters/KernelFilters/gaussianblur.h"
#include "Filters/KernelFilters/medianblur.h"

ImageController::ImageController()
{
    this->filters.push_back(new GaussianBlur("Filter 1", 1));
    this->filters.push_back(new MedianBlur("Filter 2", 1));
    this->filters.push_back(new MedianBlur("Filter 3", 1));
}

ImageController::~ImageController()
{
    for(auto obj : this->filters)
        delete obj;
}


ImageController::ImageController(const ImageController &other)
{
    this->filters.clear();

    for(auto obj : other.filters)
        this->filters.push_back(obj->clone());
}

ImageController &ImageController::operator=(const ImageController &other)
{
    this->filters.clear();

    for(auto obj : other.filters)
        this->filters.push_back(obj->clone());
    return *this;
}

void ImageController::ApplyFilters(cv::Mat &frame)
{
    for(auto obj : this->filters)
        obj->Process(frame);
}

std::vector<AbstractFilter *> ImageController::getFilters()
{
    return this->filters;
}
