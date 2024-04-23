
#ifndef PRLIB_RESIZE_HPP
#define PRLIB_RESIZE_HPP

#include <opencv2/core/core.hpp>

namespace prl
{
CV_EXPORTS void resize(const cv::Mat& src, cv::Mat& dst, int scaleX, int scaleY, int maxSize);
}

#endif //PRLIB_RESIZE_HPP
