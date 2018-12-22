#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H

#include "../abstractcolorfilter.h"

class GrayScaleFilter : public AbstractColorFilter
{
public:
    GrayScaleFilter(QString filterName);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;
};

#endif // GRAYSCALEFILTER_H
