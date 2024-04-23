
#include "cleanBackgroundToWhite.h"

#include <stdexcept>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <leptonica/allheaders.h>

#include "formatConvert.h"

namespace prl {
void cleanBackgroundToWhite(const cv::Mat& inputImage, cv::Mat& outputImage)
{
    cv::Mat inputImageMat = inputImage;

    if (inputImageMat.empty()) {
        throw std::invalid_argument("Input image for flipping is empty");
    }

    cv::Mat outputImageMat;

    {
        PIX* pixs = prl::opencvToLeptonica(&inputImageMat);

        /* Normalize for varying background */
        PIX* pixn = pixCleanBackgroundToWhite(pixs, nullptr, nullptr, 1.0, 70, 170);

        pixDestroy(&pixs);

        outputImageMat = prl::leptonicaToOpenCV(pixn);

        pixDestroy(&pixn);
    }

    outputImage = outputImageMat;
}

}