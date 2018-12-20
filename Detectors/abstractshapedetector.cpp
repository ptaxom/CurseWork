#include "abstractshapedetector.h"

AbstractShapeDetector::AbstractShapeDetector(QString detectorName, QString detectorType) :
    AbstractFilter (detectorName, detectorType)
{

}

void AbstractShapeDetector::Process(cv::Mat &image) const
{
    try {
        std::vector<cv::Rect> shapes = this->getShapesBounds(image);
        for(auto shape : shapes)
        {
            cv::Mat subImage = image(shape);
            imagePostprocessor.ApplyFilters(subImage);
        }
    } catch (...) {
        return;
    }
}

ImageController &AbstractShapeDetector::getPreprocessorRef()
{
    return this->detectorPreprocessor;
}

ImageController &AbstractShapeDetector::getPostprocessorRef()
{
    return this->imagePostprocessor;
}

