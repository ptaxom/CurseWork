#include "morpherode.h"

MorphErode::MorphErode(QString filterName, int kernelSize, int kernelType) : AbstractMorphFilter (filterName,kernelSize, kernelType)
{
    this->indexInComboBox = 1;
    this->updateKernel();
}

void MorphErode::Process(cv::Mat &image) const
{
    cv::erode(image, image,kernel);
}

AbstractFilter *MorphErode::clone() const
{
    return new MorphErode(this->getFilterName(), kernel_size, kernelType);
}
