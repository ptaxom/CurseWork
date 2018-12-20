#ifndef ABSTRACTMORPHFILTER_H
#define ABSTRACTMORPHFILTER_H

#include "abstractfilter.h"
#include <map>

class AbstractMorphFilter : public AbstractFilter
{
public:
    AbstractMorphFilter(QString filterName,  int kernelSize = 1, int kernelType = 0, QString filterType = "AbstractMorphFilter" );

    virtual void Process(cv::Mat &image) const {}
    virtual AbstractFilter* clone() const {return nullptr; }

    int getKernelSize() const;
    int getKernelType() const;

    static QString getKernelName(int type);

    void updateKernel();

protected:
    int kernel_size;
    int kernelType;
    cv::Mat kernel;

private:
    static std::map<int, QString> kernelNames;
    cv::Mat kernelFactory() const;
};

#endif // ABSTRACTMORPHFILTER_H
