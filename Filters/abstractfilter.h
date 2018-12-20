#ifndef ABSTRACTFILTER_H
#define ABSTRACTFILTER_H

#include <opencv2/imgproc.hpp>
#include <QString>

/*
 * 0x0000...0000 0000 0000 0000
 *                     ^ - type of filter (reserved, morph, color, kernel
 *                  ^ 4 bits per code of filter type
 *                  offset = 4 * ( (val & 15) - (val & 15) * (val & 15) / 4)
 *                  filter index = (val & (15 << offset)) >> offset
 */

class AbstractFilter
{
public:
    AbstractFilter(QString filterName, QString filterType = "Abstract");

    virtual void Process(cv::Mat &image) const {}
    virtual AbstractFilter* clone() const { throw std::exception("Method clone() dosn't implemented!"); return nullptr; }

    QString getFilterType() const;
    QString getFilterName() const;

    int getIndex() const;

private:
    QString filterName;
    QString filterType;

    //scratch, need to fix
protected:
    int indexInComboBox = 0;
};

#endif // ABSTRACTFILTER_H
