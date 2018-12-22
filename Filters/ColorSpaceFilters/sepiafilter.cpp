#include "sepiafilter.h"

cv::Mat_<float> SepiaFilter::kernel = (cv::Mat_<float>(4,4) <<  0.272, 0.534, 0.131, 0,
                                                   0.349, 0.686, 0.168, 0,
                                                   0.393, 0.769, 0.189, 0,
                                                   0, 0, 0, 1);

SepiaFilter::SepiaFilter(QString filterName) : AbstractColorFilter (filterName)
{
    this->indexInComboBox = -1;
}

void SepiaFilter::Process(cv::Mat &image) const
{
    cv::transform(image, image, SepiaFilter::kernel);
}


AbstractFilter *SepiaFilter::clone() const
{
    return new SepiaFilter(this->getFilterName());
}
