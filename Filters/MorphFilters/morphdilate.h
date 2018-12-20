#ifndef MORPHDILATE_H
#define MORPHDILATE_H

#include "../abstractmorphfilter.h"

class MorphDilate : public AbstractMorphFilter
{
public:
    MorphDilate(QString filterName, int kernelSize = 1, int kernelType = 0);

    void Process(cv::Mat &image) const override;
    AbstractFilter* clone() const override;

};

#endif // MORPHDILATE_H
