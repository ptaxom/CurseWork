#ifndef MORPHCLOSE_H
#define MORPHCLOSE_H

#include "../abstractmorphfilter.h"

class MorphClose : public AbstractMorphFilter
{
public:
    MorphClose(QString filterName, int kernelSize = 1, int kernelType = 0);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;

};

#endif // MORPHCLOSE_H
