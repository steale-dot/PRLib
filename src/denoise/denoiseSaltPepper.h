
#ifndef PRLIB_DENOISESALTPEPPER_H
#define PRLIB_DENOISESALTPEPPER_H

#include <opencv2/core/core.hpp>

namespace prl
{
/*!
 * \brief Remove Salt-Pepper noise.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \param[in] kernelSize Kernel size for median filter.
 * \param[in] times Filter running times.
 * \details Implementation uses medianFilter for denoising.
 */
CV_EXPORTS void denoiseSaltPepper(const cv::Mat& inputImage, cv::Mat& outputImage, int kernelSize, size_t times);
}

#endif //PRLIB_DENOISESALTPEPPER_H
