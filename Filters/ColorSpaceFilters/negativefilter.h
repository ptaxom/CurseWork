#ifndef NEGATIVEFILTER_H
#define NEGATIVEFILTER_H

#include "../abstractcolorfilter.h"

class NegativeFilter : public AbstractColorFilter
{
public:
    NegativeFilter(QString filterName);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;
};

#endif // NEGATIVEFILTER_H
