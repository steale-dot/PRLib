
#ifndef PRLIB_ROTATE
#define PRLIB_ROTATE

#include <opencv2/core/core.hpp>

namespace prl
{
/*!
 * \brief Rotate image.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \param[in] angle Rotation angle
 * \details Rotate image by provided angle.
 */
CV_EXPORTS void rotate(const cv::Mat& inputImage, cv::Mat& outputImage, double angle);
}

#endif //PRLIB_ROTATE
