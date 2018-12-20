#include "abstractfilter.h"



AbstractFilter::AbstractFilter(QString filterName, QString filterType)
{
    this->filterName = filterName;
    this->filterType = filterType;
}

QString AbstractFilter::getFilterType() const
{
    return this->filterType;
}


QString AbstractFilter::getFilterName() const
{
    return this->filterName;
}

int AbstractFilter::getIndex() const
{
    return this->indexInComboBox;
}

