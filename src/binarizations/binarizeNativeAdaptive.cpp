
#include "binarizeNativeAdaptive.h"

#include <cmath>
#include <stdexcept>
#include <vector>

#include <opencv2/imgproc/imgproc.hpp>

void prl::binarizeNativeAdaptive(
    cv::Mat& inputImage, cv::Mat& outputImage,
    bool isGaussianBlurReqiured,
    int medianBlurKernelSize,
    int GaussianBlurKernelSize,
    double GaussianBlurSigma,
    bool isAdaptiveThresholdCalculatedByGaussian,
    double adaptiveThresholdingMaxValue,
    int adaptiveThresholdingBlockSize,
    double adaptiveThresholdingShift,
    int bilateralFilterBlockSize,
    double bilateralFilterColorSigma,
    double bilateralFilterSpaceSigma)
{
    if (inputImage.empty()) {
        throw std::invalid_argument("Input image for binarization is empty");
    }

    if (!(adaptiveThresholdingMaxValue >= 0 && adaptiveThresholdingMaxValue <= 255)) {
        throw std::invalid_argument("Max value must be in range [0; 255]");
    }

    if (inputImage.channels() > 1) {
        cv::cvtColor(inputImage, inputImage, cv::COLOR_BGR2GRAY);
    }

    if (!isGaussianBlurReqiured) {
        CV_Assert(medianBlurKernelSize >= 3);
        cv::medianBlur(inputImage, outputImage, medianBlurKernelSize);
    } else {
        CV_Assert(GaussianBlurKernelSize >= 3);
        CV_Assert(GaussianBlurSigma > 0);
        cv::GaussianBlur(inputImage, outputImage,
            cv::Size(GaussianBlurKernelSize, GaussianBlurKernelSize),
            GaussianBlurSigma);
    }

    int adaptiveMethod = cv::ADAPTIVE_THRESH_MEAN_C;

    if (isAdaptiveThresholdCalculatedByGaussian) {
        adaptiveMethod = cv::ADAPTIVE_THRESH_GAUSSIAN_C;
    }

    std::vector<cv::Mat> inputImageChannels(outputImage.channels());
    cv::split(outputImage, inputImageChannels);

    if (adaptiveThresholdingBlockSize < 3) {
        double diagonal = std::sqrt(outputImage.rows * outputImage.rows + outputImage.cols * outputImage.cols);

        adaptiveThresholdingBlockSize = static_cast<int>(diagonal / 333 + 7);
    }

    for (size_t channelNo = 0; channelNo < inputImageChannels.size(); ++channelNo) {
        cv::adaptiveThreshold(
            inputImageChannels[channelNo],
            inputImageChannels[channelNo],
            adaptiveThresholdingMaxValue,
            adaptiveMethod, cv::THRESH_BINARY_INV,
            adaptiveThresholdingBlockSize,
            adaptiveThresholdingShift);

        if (cv::mean(inputImageChannels[channelNo])[0] < 128) {
            inputImageChannels[channelNo] = 255 - inputImageChannels[channelNo];
        }
    }

    cv::merge(inputImageChannels, outputImage);

    if (bilateralFilterBlockSize >= 3) {

        if (bilateralFilterColorSigma <= 0) {
            throw std::invalid_argument("Color sigma for bilateral filtration must be greater than 0");
        }

        if (bilateralFilterSpaceSigma <= 0) {
            throw std::invalid_argument("Space sigma for bilateral filtration must be greater than 0");
        }

        cv::Mat outputImageMatTmp = outputImage.clone();
        cv::bilateralFilter(outputImageMatTmp, outputImage,
            bilateralFilterBlockSize,
            bilateralFilterColorSigma,
            bilateralFilterSpaceSigma);
    }
}