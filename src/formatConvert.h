
#ifndef PRLIB_FORMATCONVERT_HPP
#define PRLIB_FORMATCONVERT_HPP

#include <opencv2/core/core.hpp>

#include "leptonica/alltypes.h"
#include <leptonica/allheaders.h>


namespace prl
{
PIX* opencvToLeptonica(const cv::Mat* inputImage);
cv::Mat leptonicaToOpenCV(PIX* inputImage);
}

#endif //PRLIB_FORMATCONVERT_HPP
