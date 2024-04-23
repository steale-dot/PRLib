
#ifndef PRLIB_REMOVEDOTS_H
#define PRLIB_REMOVEDOTS_H

#include <opencv2/core/core.hpp>

namespace prl
{
/*!
 * \brief Remove dots on an image.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \details Delete dots on an image.
 */
CV_EXPORTS void removeDots(const cv::Mat& inputImage, cv::Mat& outputImage, const double radius = -1.0);
}

#endif //PRLIB_REMOVEDOTS_H
