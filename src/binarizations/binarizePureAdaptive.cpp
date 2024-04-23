
#include "binarizePureAdaptive.h"

#include <stdexcept>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void prl::binarizePureAdaptive(const cv::Mat& inputImage, cv::Mat& outputImage,
    const double maxValue, const int blockSize, const int shift)
{
    cv::Mat inputImageMat = inputImage.clone();

    if (inputImageMat.empty()) {
        throw std::invalid_argument("Input image for binarization is empty");
    }

    if (inputImageMat.channels() != 1) {
        cv::cvtColor(inputImageMat, inputImageMat, cv::COLOR_BGR2GRAY);
    }

    cv::Mat outputImageMat;

    if (inputImageMat.channels() != 1) {
        cv::cvtColor(inputImageMat, outputImageMat, cv::COLOR_BGR2GRAY);
    }

    cv::adaptiveThreshold(
        outputImageMat, outputImageMat,
        maxValue,
        cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY,
        blockSize, shift);

    outputImage = outputImageMat;
}
