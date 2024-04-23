
#ifndef PRLIB_BackgroundNormalization_Lepton_h
#define PRLIB_BackgroundNormalization_Lepton_h

#include <opencv2/core/core.hpp>

namespace prl
{
/*!
 * \brief Normalize background.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \details Implementation is based on Leptonica library
 * \note Implementation of this procedure is based on
 * <a href="http://www.leptonica.com/">Leptonica library</a>..
 */
CV_EXPORTS void backgroundNormalization(const cv::Mat& inputImage, cv::Mat& outputImage);
}

#endif // PRLIB_BackgroundNormalization_Lepton_h
