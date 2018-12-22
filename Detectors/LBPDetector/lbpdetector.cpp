#include "lbpdetector.h"

#include <QDebug>

LBPDetector::LBPDetector(QString detectorName, ImageController preproc, ImageController postproc) :
    AbstractShapeDetector (detectorName, preproc, postproc)
{
    this->indexInComboBox = 0;
    cv::Ptr<cv::CascadeClassifier> cascade = cv::makePtr<cv::CascadeClassifier>(this->defaultPath);
    cv::Ptr<cv::DetectionBasedTracker::IDetector> MainDetector = cv::makePtr<DetectorAdapter::CascadeDetectorAdapter>(cascade);


    cascade = cv::makePtr<cv::CascadeClassifier>(this->defaultPath);
    cv::Ptr<cv::DetectionBasedTracker::IDetector> TrackingDetector = cv::makePtr<DetectorAdapter::CascadeDetectorAdapter>(cascade);
        if ( cascade->empty() )
        {
          throw std::runtime_error("Cann't load cascade in LBPDetector constructor...");
        }

        cv::DetectionBasedTracker::Parameters params;
        detector = new cv::DetectionBasedTracker(MainDetector, TrackingDetector, params);
}

std::vector<cv::Rect> LBPDetector::getShapesBounds(const cv::Mat &image) const
{
    cv::Mat buffer;
    image.copyTo(buffer);
    this->detectorPreprocessor.ApplyFilters(buffer);
    std::vector<cv::Rect> shapes;

    cv::cvtColor(buffer, buffer, cv::COLOR_BGR2GRAY);
    detector->process(buffer);
    detector->getObjects(shapes);

    return shapes;
}

AbstractFilter *LBPDetector::clone() const
{
    return new LBPDetector(this->getFilterName(), detectorPreprocessor, imagePostprocessor);
}

LBPDetector::~LBPDetector()
{
    if (this->detector)
        delete this->detector;
}
