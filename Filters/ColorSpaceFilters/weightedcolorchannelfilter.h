#ifndef WEIGHTEDCOLORCHANNELFILTER_H
#define WEIGHTEDCOLORCHANNELFILTER_H


#include "../abstractcolorfilter.h"

class WeightedColorChannelFilter : public AbstractColorFilter
{
public:
    WeightedColorChannelFilter(QString filterName,double r = 1.0, double g = 1.0, double b = 1.0);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;

    double getR() const;
    double getG() const;
    double getB() const;

private:
    double r;
    double g;
    double b;
};

#endif // WEIGHTEDCOLORCHANNELFILTER_H
