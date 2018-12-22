#include "grayscalefilter.h"

GrayScaleFilter::GrayScaleFilter(QString filterName) : AbstractColorFilter(filterName)
{
    this->indexInComboBox = 1;
}

void GrayScaleFilter::Process(cv::Mat &image) const
{
    cv::cvtColor(image,image,CV_BGR2GRAY);
}

AbstractFilter *GrayScaleFilter::clone() const
{
    return new GrayScaleFilter(this->getFilterName());
}

