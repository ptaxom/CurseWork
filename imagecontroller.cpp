#include "imagecontroller.h"

#include "Filters/KernelFilters/gaussianblur.h"
#include "Filters/KernelFilters/medianblur.h"

ImageController::ImageController()
{

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

void ImageController::ApplyFilters(cv::Mat &frame) const
{
    for(auto obj : this->filters)
        obj->Process(frame);
}

void ImageController::Clone(const ImageController &other)
{
    this->filters.clear();

    for(auto obj : other.filters)
        this->filters.push_back(obj->clone());
}

std::vector<AbstractFilter *> &ImageController::getFilters()
{
    return this->filters;
}
