#ifndef ABSTRACTSHAPEDETECTOR_H
#define ABSTRACTSHAPEDETECTOR_H


#include "../imagecontroller.h"
#include "../Filters/abstractfilter.h"

#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>

class AbstractShapeDetector : public AbstractFilter
{
public:
    AbstractShapeDetector(QString detectorName, QString detectorType = "AbstractDetector");

    virtual std::vector<cv::Rect>  getShapesBounds(const cv::Mat &image) const
    {
        throw std::exception("Something goes wrong...");
        return std::vector<cv::Rect>();
    }

    void Process(cv::Mat &image) const override;

    virtual AbstractFilter* clone() const { return nullptr; }

    QString getFilterType() const;
    QString getFilterName() const;

    int getIndex() const;

    ImageController& getPreprocessorRef();
    ImageController& getPostprocessorRef();


private:

    ImageController detectorPreprocessor;
    ImageController imagePostprocessor;

};

#endif // ABSTRACTSHAPEDETECTOR_H
