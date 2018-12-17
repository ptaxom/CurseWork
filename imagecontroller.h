#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include<memory>
#include <vector>
#include "Filters/abstractfilter.h"


class ImageController
{
public:
    ImageController();
    ~ImageController();

    ImageController(const ImageController &other);
    ImageController& operator=(const ImageController &other);

    void ApplyFilters(cv::Mat &frame);

    void Clone(const ImageController &other);

    std::vector<AbstractFilter *> &getFilters();

private:
    std::vector<AbstractFilter*> filters;
};

using AbstPtr = std::shared_ptr<AbstractFilter>;


#endif // IMAGECONTROLLER_H
