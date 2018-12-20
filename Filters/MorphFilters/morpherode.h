#ifndef MORPHERODE_H
#define MORPHERODE_H

#include "../abstractmorphfilter.h"

class MorphErode : public AbstractMorphFilter
{
public:
    MorphErode(QString filterName, int kernelSize = 1, int kernelType = 0);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;

};

#endif // MORPHERODE_H
