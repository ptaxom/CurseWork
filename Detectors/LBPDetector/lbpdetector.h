#ifndef LBPDETECTOR_H
#define LBPDETECTOR_H

#include "../abstractshapedetector.h"


namespace DetectorAdapter
{
    class CascadeDetectorAdapter : public cv::DetectionBasedTracker::IDetector
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
            cv::Ptr<cv::CascadeClassifier> Detector;
     };
}


class LBPDetector : public AbstractShapeDetector
{
public:
    LBPDetector(QString detectorName, ImageController preproc, ImageController postproc);


    std::vector<cv::Rect>  getShapesBounds(const cv::Mat &image) const override;
    AbstractFilter* clone() const override;


    ~LBPDetector();


private:
    std::string defaultPath = "../data/lbpcascades/lbpcascade_frontalface.xml"; //"D:/Qtproj/data/lbpcascades/lbpcascade_frontalface.xml"
    cv::DetectionBasedTracker *detector = nullptr;
};

#endif // LBPDETECTOR_H
