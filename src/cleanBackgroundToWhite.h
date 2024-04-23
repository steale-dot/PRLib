
#ifndef PRLIB_CLEANBACKGROUNDTOWHITE_H
#define PRLIB_CLEANBACKGROUNDTOWHITE_H

#include <opencv2/core/core.hpp>

namespace prl
{
/*!
 * \brief Clean image background to white color.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \details Implementation is based on Leptonica library
 * \note Implementation of this procedure is based on
 * <a href="http://www.leptonica.com/">Leptonica library</a>..
 */
    CV_EXPORTS void cleanBackgroundToWhite(const cv::Mat& inputImage, cv::Mat& outputImage);
}

#endif //PRLIB_CLEANBACKGROUNDTOWHITE_H
