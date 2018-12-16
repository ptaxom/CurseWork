#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

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

    std::vector<AbstractFilter*> getFilters();

private:
    std::vector<AbstractFilter*> filters;
};

#endif // IMAGECONTROLLER_H
