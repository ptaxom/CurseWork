#include "grayscalefilter.h"

GrayScaleFilter::GrayScaleFilter(QString filterName) : AbstractColorFilter(filterName)
{
    this->indexInComboBox = 3;
}

void GrayScaleFilter::Process(cv::Mat &image) const
{
    cv::bitwise_not(image, image);
}

AbstractFilter *GrayScaleFilter::clone() const
{
    return new GrayScaleFilter(this->getFilterName());
}

