#include "abstractmorphfilter.h"


std::map<int, QString> AbstractMorphFilter::kernelNames = {{0, QString("Квадратное ядро")},
                                                           {1, QString("Округлое ядро")},
                                                           {2, QString("Крестовидное ядро")},
                                                          };


AbstractMorphFilter::AbstractMorphFilter(QString filterName, int kernelSize, int kernelType, QString filterType) :
    AbstractFilter (filterName, filterType)
{
    this->kernelType = kernelType;
    this->kernel_size = kernelSize;
}

int AbstractMorphFilter::getKernelSize() const
{
    return this->kernel_size;
}

int AbstractMorphFilter::getKernelType() const
{
    return this->kernelType;
}

QString AbstractMorphFilter::getKernelName(int type)
{
    if (0 <= type && type < kernelNames.size())
        return kernelNames[type];
    else throw std::exception("Out of bounds");
}

void AbstractMorphFilter::updateKernel()
{
    this->kernel = kernelFactory();
}

cv::Mat AbstractMorphFilter::kernelFactory() const
{
    int type;
    switch (this->kernelType) {
    case 0 : type = cv::MORPH_RECT; break;
    case 1 : type = cv::MORPH_ELLIPSE; break;
    case 2 : type = cv::MORPH_CROSS; break;
    default: type = cv::MORPH_RECT;
    }
    int fullKernelSize = this->kernel_size * 2 + 1;
    cv::Mat kernel = cv::getStructuringElement(type, cv::Size(fullKernelSize, fullKernelSize), cv::Point(kernel_size, kernel_size));
    return kernel;
}
