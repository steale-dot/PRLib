#ifndef PRLIB_KUWAHARA_FILTER_H
#define PRLIB_KUWAHARA_FILTER_H

#include <opencv2/core/core.hpp>

#include <cmath>
#include <vector>

namespace prl
{
    void denoiseKuwahara(const cv::Mat& input_img, cv::Mat& outputImage, size_t iterations);
}



#endif //PRLIB_KUWAHARA_FILTER_H

