#include "morphdilate.h"


MorphDilate::MorphDilate(QString filterName, int kernelSize, int kernelType) : AbstractMorphFilter (filterName,kernelSize, kernelType)
{
    this->indexInComboBox = 0;
    this->updateKernel();
}

void MorphDilate::Process(cv::Mat &image) const
{
    cv::dilate(image, image,kernel);
}

AbstractFilter *MorphDilate::clone() const
{
    return new MorphDilate(this->getFilterName(), kernel_size, kernelType);
}
