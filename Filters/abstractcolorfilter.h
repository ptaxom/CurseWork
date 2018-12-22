#ifndef ABSTRACTCOLORFILTER_H
#define ABSTRACTCOLORFILTER_H

#include "abstractfilter.h"

class AbstractColorFilter : public AbstractFilter
{
public:
    AbstractColorFilter(QString filterName);

    virtual void Process(cv::Mat &image) const {}
    virtual AbstractFilter* clone() const {return nullptr; }


};

#endif // ABSTRACTCOLORFILTER_H
