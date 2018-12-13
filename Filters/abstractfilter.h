#ifndef ABSTRACTFILTER_H
#define ABSTRACTFILTER_H

#include <opencv2/imgproc.hpp>
#include <QString>

class AbstractFilter
{
public:
    AbstractFilter(QString filterName, QString filterType = "Abstract");

    virtual void Process(cv::Mat &image);

    QString getFilterName() const;
    QString getFilterType() const;

private:
    QString filterName;
    QString filterType;
};

#endif // ABSTRACTFILTER_H
