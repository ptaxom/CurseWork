#include "abstractfilter.h"



AbstractFilter::AbstractFilter(QString filterName, QString filterType)
{
    this->filterName = filterName;
    this->filterType = filterType;
}

void AbstractFilter::Process(cv::Mat &image)
{

}

QString AbstractFilter::getFilterName() const
{
    return filterName;
}

QString AbstractFilter::getFilterType() const
{
    return filterType;
}
