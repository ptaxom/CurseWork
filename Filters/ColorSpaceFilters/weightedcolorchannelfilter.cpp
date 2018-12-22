#include "weightedcolorchannelfilter.h"



WeightedColorChannelFilter::WeightedColorChannelFilter(QString filterName, double r_, double g_, double b_) :
    AbstractColorFilter (filterName),
    r(r_),
    g(g_),
    b(b_)
{
    this->indexInComboBox = 4;
}

void WeightedColorChannelFilter::Process(cv::Mat &image) const
{
    std::vector<cv::Mat> channels;
    cv::split(image, channels);
    if (!channels.empty()){
        cv::Mat black(channels[0].rows, channels[0].cols ,channels[0].type(), cv::Scalar(255,255,255));
        cv::addWeighted(channels[0], b, black, b < 0 ? 1 : 0  , 0, channels[0]);
        cv::addWeighted(channels[1], g, black, g < 0 ? 1 : 0  , 0, channels[1]);
        cv::addWeighted(channels[2], r, black, r < 0 ? 1 : 0  , 0, channels[2]);
        cv::merge(channels,image);
    }
}

AbstractFilter *WeightedColorChannelFilter::clone() const
{
    return new WeightedColorChannelFilter(this->getFilterName(),r,g,b);
}

double WeightedColorChannelFilter::getR() const
{
    return r;
}

double WeightedColorChannelFilter::getG() const
{
    return g;
}

double WeightedColorChannelFilter::getB() const
{
    return b;
}
