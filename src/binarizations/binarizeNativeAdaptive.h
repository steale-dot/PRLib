
#ifndef PRLIB_binarizeNativeAdaptive_h
#define PRLIB_binarizeNativeAdaptive_h

#include <opencv2/core/core.hpp>

namespace prl
{

/*!
 * \brief Native adaptive thresholding.
 * \param inputImage Image for binarization.
 * \param outputImage Resulting image.
 * \param isGaussianBlurReqiured \parblock Flag of usage Gaussian blur.
 * If this flag equals true then Gaussian blur is used.
 * Else median blur is used. \endparblock
 * \param medianBlurKernelSize Kernel size for median blur.
 * \param GaussianBlurKernelSize Kernel size for Gaussian blur.
 * \param GaussianBlurSigma Gaussian blur \f$\sigma\f$.
 * \param isAdaptiveThresholdCalculatedByGaussian \parblock
 * Flag of base of adaptive thresholding type.
 * If this flag equals true then Gaussian kernel is used.
 * Else mean kernel is used. \endparblock
 * \param adaptiveThresholdingMaxValue \parblock 
 * New value for pixel which intensity greater than threshold value.
 * \endparblock
 * \param adaptiveThresholdingBlockSize Kernel size for adaptive thresholding procedure.
 * \param adaptiveThresholdingShift Shifting value for adaptive thresholding procedure.
 * \param bilateralFilterBlockSize \parblock 
 * Kernel size for bilateral filtration. If less than 0 then filtration isn't used.
 * \endparblock
 * \param bilateralFilterColorSigma Sigma (\f$\sigma_r\f$) for intensity range.
 * \param bilateralFilterSpaceSigma Sigma (\f$\sigma_d\f$) for space range.
 * \details This function consists of next steps:
 * -# Median/Gaussian blur.
 * -# Adaptive threshold.
 * -# Bilateral filter.
 */
CV_EXPORTS void binarizeNativeAdaptive(
		cv::Mat& inputImage, cv::Mat& outputImage,
		bool isGaussianBlurReqiured = 0,
		int medianBlurKernelSize = 5,
		int GaussianBlurKernelSize = 7,
		double GaussianBlurSigma = 150.0,
		bool isAdaptiveThresholdCalculatedByGaussian = true,
		double adaptiveThresholdingMaxValue = 255.0,
		int adaptiveThresholdingBlockSize = 19,
		double adaptiveThresholdingShift = 9,
		int bilateralFilterBlockSize = 0,
		double bilateralFilterColorSigma = 150.0,
		double bilateralFilterSpaceSigma = 150.0);

}
#endif // PRLIB_binarizeNativeAdaptive_h
