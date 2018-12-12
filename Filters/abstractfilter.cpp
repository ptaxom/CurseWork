#include "abstractfilter.h"


AbstractFilter::AbstractFilter(QString filterName)
{
    this->filterName = filterName;
}

void AbstractFilter::Process(cv::Mat &image)
{

}

QString AbstractFilter::getFilterName() const
{
    return filterName;
}
