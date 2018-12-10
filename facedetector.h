#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <vector>

#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/objdetect.hpp>

namespace Detector {


class CascadeDetectorAdapter: public cv::DetectionBasedTracker::IDetector
{
    public:
        CascadeDetectorAdapter(cv::Ptr<cv::CascadeClassifier> detector):
            cv::DetectionBasedTracker::IDetector(),
            Detector(detector)
        {
            CV_Assert(detector);
        }

        void detect(const cv::Mat &Image, std::vector<cv::Rect> &objects)
        {
            Detector->detectMultiScale(Image, objects, scaleFactor, minNeighbours, 0, minObjSize, maxObjSize);
        }

        virtual ~CascadeDetectorAdapter()
        {}

    private:
        CascadeDetectorAdapter();
        cv::Ptr<cv::CascadeClassifier> Detector;
 };


class FaceDetector
{
public:
    FaceDetector();

    std::vector<cv::Rect> getFaces(const cv::Mat &frame);

private:
    cv::DetectionBasedTracker *detector = nullptr;
};


}
#endif // FACEDETECTOR_H
