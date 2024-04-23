
#ifndef NiblackBinarizerImpl_h__
#define NiblackBinarizerImpl_h__

#include <opencv2/core/core.hpp>

namespace prl
{

/*!
* \brief Niblack binarization algorithm implementation.
* \param inputImage Image for processing.
* \param outputImage Resulting binary image.
* \param windowSize Size of sliding window.
* \param thresholdCoefficient Coefficient for threshold calculation.
* \param morphIterationCount Count of morphology operation in postprocessing.
* \details This function implements algorithm described in article
* "Comparison of Niblack inspired Binarization methods for ancient documents".
*/
CV_EXPORTS void binarizeNiblack(
		cv::Mat& inputImage, cv::Mat& outputImage,
		int windowSize = 101,
		double thresholdCoefficient = 0.01,
		int morphIterationCount = 2);

}
#endif // NiblackBinarizerImpl_h__
