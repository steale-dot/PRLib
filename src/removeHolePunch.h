
#ifndef PRLIB_REMOVEHOLEPUNCH_H
#define PRLIB_REMOVEHOLEPUNCH_H

#include <opencv2/core/core.hpp>

namespace prl
{
/*!
 * \brief Remove hole punches on an image.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \details Remove hole punches on an image. Hole punch is blob near page border.
 */
CV_EXPORTS void removeHolePunch(const cv::Mat& inputImage, cv::Mat& outputImage);
}

#endif //PRLIB_REMOVEHOLEPUNCH_H
