
#ifndef PRLIB_NICKBinarizerImpl_h
#define PRLIB_NICKBinarizerImpl_h

#include <opencv2/core/core.hpp>

namespace prl
{

/*!
* \brief NICK binarization algorithm implementation.
* \param inputImage Image for processing.
* \param outputImage Resulting binary image.
* \param windowSize Size of sliding window.
* \param thresholdCoefficient Coefficient for threshold calculation.
* \param morphIterationCount Count of morphology operation in postprocessing.
* \details This function implements algorithm described in article
* "Comparison of Niblack inspired Binarization methods for ancient documents".
*/
CV_EXPORTS void binarizeNICK(
		cv::Mat& inputImage, cv::Mat& outputImage,
		int windowSize = 21,
		double thresholdCoefficient = -0.01,
		int morphIterationCount = 0);

}
#endif // PRLIB_NICKBinarizerImpl_h
