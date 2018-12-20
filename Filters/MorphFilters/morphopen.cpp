#include "morphopen.h"

MorphOpen::MorphOpen(QString filterName, int kernelSize, int kernelType) : AbstractMorphFilter (filterName,kernelSize, kernelType)
{
    this->indexInComboBox = 2;
    this->updateKernel();
}

void MorphOpen::Process(cv::Mat &image) const
{
    cv::dilate(image, image, kernel);
    cv::erode(image, image,kernel);
}

AbstractFilter *MorphOpen::clone() const
{
    return new MorphOpen(this->getFilterName(), kernel_size, kernelType);
}
