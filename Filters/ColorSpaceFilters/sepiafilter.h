#ifndef SEPIAFILTER_H
#define SEPIAFILTER_H

#include "../abstractcolorfilter.h"

class SepiaFilter : public AbstractColorFilter
{
public:
    SepiaFilter(QString filterName);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;
private:
    static cv::Mat_<float> kernel;
};

#endif // SEPIAFILTER_H
