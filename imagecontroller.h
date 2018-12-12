#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include <vector>
#include "Filters/abstractfilter.h"


class ImageController
{
public:
    ImageController();
    ~ImageController();

    void ApplyFilters(cv::Mat &frame);

private:
    std::vector<AbstractFilter*> filters;
};

#endif // IMAGECONTROLLER_H
