#include "facedetector.h"


namespace Detector {


FaceDetector::FaceDetector()
{
    std::string cascadeFrontalfilename = "D:/Qtproj/CourseWork/data/lbpcascades/lbpcascade_frontalface.xml";
    cv::Ptr<cv::CascadeClassifier> cascade = cv::makePtr<cv::CascadeClassifier>(cascadeFrontalfilename);
    cv::Ptr<cv::DetectionBasedTracker::IDetector> MainDetector = cv::makePtr<Detector::CascadeDetectorAdapter>(cascade);


    cascade = cv::makePtr<cv::CascadeClassifier>(cascadeFrontalfilename);
        cv::Ptr<cv::DetectionBasedTracker::IDetector> TrackingDetector = cv::makePtr<Detector::CascadeDetectorAdapter>(cascade);
        if ( cascade->empty() )
        {
          printf("Error: Cannot load %s\n", cascadeFrontalfilename.c_str());
        }

        cv::DetectionBasedTracker::Parameters params;
        detector =new cv::DetectionBasedTracker(MainDetector, TrackingDetector, params);

}

std::vector<cv::Rect> FaceDetector::getFaces(const cv::Mat &frame)
{
    cv::Mat GrayFrame;
    std::vector<cv::Rect> Faces;

    cv::cvtColor(frame, GrayFrame, cv::COLOR_BGR2GRAY);
    detector->process(GrayFrame);
    detector->getObjects(Faces);

    return Faces;
}

}
