
#include "backgroundNormalization.h"

#include <stdexcept>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <leptonica/allheaders.h>

#include "formatConvert.h"

void prl::backgroundNormalization(const cv::Mat& inputImage, cv::Mat& outputImage)
{
    cv::Mat inputImageMat = inputImage;

    if (inputImageMat.empty()) {
        throw std::invalid_argument("Input image for flipping is empty");
    }

    cv::Mat outputImageMat;

    {
        PIX* pixs = prl::opencvToLeptonica(&inputImageMat);

        /* Normalize for varying background */
        PIX* pixn = pixBackgroundNormSimple(pixs, nullptr, nullptr);

        pixDestroy(&pixs);

        outputImageMat = prl::leptonicaToOpenCV(pixn);

        pixDestroy(&pixn);
    }

    outputImage = outputImageMat;
}