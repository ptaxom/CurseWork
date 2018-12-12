#ifndef ABSTRACTFILTER_H
#define ABSTRACTFILTER_H

#include <opencv2/imgproc.hpp>
#include <QString>

class AbstractFilter
{
public:
    AbstractFilter(QString filterName);

    virtual void Process(cv::Mat &image);

    QString getFilterName() const;

private:
    QString filterName;
};

#endif // ABSTRACTFILTER_H
