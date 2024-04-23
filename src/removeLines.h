
#ifndef PRLIB_REMOVELINES_H
#define PRLIB_REMOVELINES_H

#include <opencv2/core/core.hpp>

namespace prl
{
/*!
 * \brief Remove lines on an image.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \details Delete horizontal and vertical lines on an image.
 */
CV_EXPORTS void removeLines(const cv::Mat& inputImage, cv::Mat& outputImage);
}

#endif //PRLIB_REMOVELINES_H
