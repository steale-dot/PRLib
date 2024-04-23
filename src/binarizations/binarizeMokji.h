
#ifndef PRLIB_BINARIZEMOKJI_H
#define PRLIB_BINARIZEMOKJI_H

#include <opencv2/core/core.hpp>

namespace prl
{

/**
* \brief Image binarization using Mokji's global thresholding method.
*
* M. M. Mokji, S. A. R. Abu-Bakar: Adaptive Thresholding Based on
* Co-occurrence Matrix Edge Information. Asia International Conference on
* Modelling and Simulation 2007: 444-450
* http://www.academypublisher.com/jcp/vol02/no08/jcp02084452.pdf
*
* \param inputImage The source image.
* \param outputImage Binarized image.
* \param maxEdgeWidth The maximum gradient length to consider.
* \param minEdgeMagnitude The minimum color difference in a gradient.
*/
CV_EXPORTS void binarizeMokji(const cv::Mat& inputImage, cv::Mat& outputImage,
                              size_t maxEdgeWidth = 3, size_t minEdgeMagnitude = 20);

}

#endif //PRLIB_BINARIZEMOKJI_H
