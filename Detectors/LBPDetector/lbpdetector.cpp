#include "lbpdetector.h"

LBPDetector::LBPDetector(QString detectorName) : AbstractShapeDetector (detectorName)
{
    this->indexInComboBox = 0;
    cv::Ptr<cv::CascadeClassifier> cascade = cv::makePtr<cv::CascadeClassifier>(this->defaultPath);
    cv::Ptr<cv::DetectionBasedTracker::IDetector> MainDetector = cv::makePtr<DetectorAdapter::CascadeDetectorAdapter>(cascade);


    cascade = cv::makePtr<cv::CascadeClassifier>(this->defaultPath);
    cv::Ptr<cv::DetectionBasedTracker::IDetector> TrackingDetector = cv::makePtr<DetectorAdapter::CascadeDetectorAdapter>(cascade);
        if ( cascade->empty() )
        {
          throw std::exception("some exception from lbp detector...");
        }

        cv::DetectionBasedTracker::Parameters params;
        detector = new cv::DetectionBasedTracker(MainDetector, TrackingDetector, params);
}

std::vector<cv::Rect> LBPDetector::getShapesBounds(const cv::Mat &image) const
{
    cv::Mat buffer(image);
    this->detectorPreprocessor.ApplyFilters(buffer);
    std::vector<cv::Rect> shapes;

    cv::cvtColor(buffer, buffer, cv::COLOR_BGR2GRAY);
    detector->process(buffer);
    detector->getObjects(shapes);

    return shapes;
}

AbstractFilter *LBPDetector::clone() const
{
    return new LBPDetector(this->getFilterName());
}

LBPDetector::~LBPDetector()
{
    if (this->detector)
        delete this->detector;
}
