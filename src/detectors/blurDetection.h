
#ifndef PRLIB_BLURDETECTION_HPP
#define PRLIB_BLURDETECTION_HPP

#include <opencv2/core/core.hpp>

namespace prl
{

CV_EXPORTS bool isBlurred(const cv::Mat& inputImage);

}
#endif //PRLIB_BLURDETECTION_HPP
