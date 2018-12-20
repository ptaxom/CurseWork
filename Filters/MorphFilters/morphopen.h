#ifndef MORPHOPEN_H
#define MORPHOPEN_H

#include "../abstractmorphfilter.h"

class MorphOpen : public AbstractMorphFilter
{
public:
    MorphOpen(QString filterName, int kernelSize = 1, int kernelType = 0);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;

};
#endif // MORPHOPEN_H
