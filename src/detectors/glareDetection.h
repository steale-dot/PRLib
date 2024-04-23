
#ifndef PRLIB_GLAREDETECTION_HPP
#define PRLIB_GLAREDETECTION_HPP

#include <opencv2/core/core.hpp>

namespace prl
{
CV_EXPORTS bool isGlared(const cv::Mat& inputImage);
}

#endif //PRLIB_GLAREDETECTION_HPP
