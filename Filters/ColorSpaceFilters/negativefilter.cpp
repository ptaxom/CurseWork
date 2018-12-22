#include "negativefilter.h"

NegativeFilter::NegativeFilter(QString filterName) : AbstractColorFilter(filterName)
{
    this->indexInComboBox = 0;
}

void NegativeFilter::Process(cv::Mat &image) const
{
    cv::bitwise_not(image, image);
}

AbstractFilter *NegativeFilter::clone() const
{
    return new NegativeFilter(this->getFilterName());
}

