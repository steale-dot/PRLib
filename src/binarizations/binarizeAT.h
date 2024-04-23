
#ifndef PRLIB_binarizeAT_H
#define PRLIB_binarizeAT_H

#include <opencv2/core/core.hpp>

namespace prl
{

CV_EXPORTS void binarizeAT(const cv::Mat& inputImage, cv::Mat& outputImage, const int medianKernelSize,
                     const double maxValue, const int blockSize, const int shift);

}

#endif // PRLIB_binarizeAT_H

