#ifndef ABSTRACTSHAPEDETECTOR_H
#define ABSTRACTSHAPEDETECTOR_H


#include "../imagecontroller.h"
#include "../Filters/abstractfilter.h"


#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/objdetect.hpp>


class AbstractShapeDetector : public AbstractFilter
{
public:
    AbstractShapeDetector(QString detectorName,
                          ImageController preproc,
                          ImageController postproc);

    virtual std::vector<cv::Rect> getShapesBounds(const cv::Mat &image) const
    {
        throw std::exception("Something goes wrong...");
        return std::vector<cv::Rect>();
    }

    void Process(cv::Mat &image) const override;


    ImageController& getPreprocessorRef();
    ImageController& getPostprocessorRef();


protected:

    ImageController detectorPreprocessor;
    ImageController imagePostprocessor;

};

#endif // ABSTRACTSHAPEDETECTOR_H
