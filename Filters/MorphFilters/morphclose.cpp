#include "morphclose.h"


MorphClose::MorphClose(QString filterName, int kernelSize, int kernelType) : AbstractMorphFilter (filterName,kernelSize, kernelType)
{
    this->indexInComboBox = 3;
    this->updateKernel();
}

void MorphClose::Process(cv::Mat &image) const
{
    cv::erode(image, image,kernel);
    cv::dilate(image, image, kernel);
}

AbstractFilter *MorphClose::clone() const
{
    return new MorphClose(this->getFilterName(), kernel_size, kernelType);
}
