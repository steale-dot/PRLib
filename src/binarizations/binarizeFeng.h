
#ifndef PRLIB_FengBinarizerImpl_h
#define PRLIB_FengBinarizerImpl_h

#include <opencv2/core/core.hpp>

namespace prl
{

/*!
* \brief Feng binarization algorithm implementation.
* \param inputImage Image for processing.
* \param outputImage Resulting binary image.
* \param windowSize Size of sliding window.
* \param thresholdCoefficient_alpha1 Coefficient \f$\alpha_1\f$ for threshold calculation.
* \param thresholdCoefficient_k1 Coefficient \f$k_1\f$ for threshold calculation.
* \param thresholdCoefficient_k2 Coefficient \f$k_2\f$ for threshold calculation.
* \param thresholdCoefficient_gamma Coefficient \f$\gamma\f$ for threshold calculation.
* \param morphIterationCount Count of morphology operation in postprocessing.
* \details This function implements algorithm described in article
* "Comparison of Niblack inspired Binarization methods for ancient documents".
*/
CV_EXPORTS void binarizeFeng(
		cv::Mat& inputImage, cv::Mat& outputImage,
		int windowSize = 21,
		double thresholdCoefficient_alpha1 = 0.75,
		double thresholdCoefficient_k1 = 0.2,
		double thresholdCoefficient_k2 = 0.03,
		double thresholdCoefficient_gamma = 2.0,
		int morphIterationCount = 2);

}
#endif // PRLIB_FengBinarizerImpl_h
