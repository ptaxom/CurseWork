#ifndef ABSTRACTSHAPEDETECTOR_H
#define ABSTRACTSHAPEDETECTOR_H


#include "../imagecontroller.h"

#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>

class AbstractShapeDetector
{
public:
    AbstractShapeDetector(QString detectorName, QString detectorType = "AbstractDetector");

    virtual std::vector<cv::Rect>  getShapesBounds(const cv::Mat &image) const
    {
        throw std::exception("Something goes wrong...");
        return std::vector<cv::Rect>();
    }

    void ProcessShapes(cv::Mat &image) const;

    QString getDetectorName() const;
    QString getDetectorType() const;

    ImageController& getPreprocessorRef();
    ImageController& getPostprocessorRef();


private:

    ImageController detectorPreprocessor;
    ImageController imagePostprocessor;

    QString detectorName;
    QString detectorType;
};

#endif // ABSTRACTSHAPEDETECTOR_H
