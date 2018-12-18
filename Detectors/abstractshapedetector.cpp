#include "abstractshapedetector.h"

AbstractShapeDetector::AbstractShapeDetector(QString detectorName, QString detectorType)
{
    this->detectorName = detectorName;
    this->detectorType = detectorType;

}

void AbstractShapeDetector::ProcessShapes(cv::Mat &image) const
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
