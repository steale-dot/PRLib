
#ifndef PRLIB_DENOISING_HPP
#define PRLIB_DENOISING_HPP

#include <opencv2/core/core.hpp>

namespace prl
{
CV_EXPORTS void denoise(const cv::Mat& inputImage, cv::Mat& outputImage, double strength = 5.5);
}


#endif //PRLIB_DENOISING_HPP
