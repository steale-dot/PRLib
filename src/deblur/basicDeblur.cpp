
#include "basicDeblur.h"

#include <stdexcept>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void prl::basicDeblur(const cv::Mat& inputImage, cv::Mat& outputImage,
    const size_t gaussianKernelSize, const double sigmaX, const double sigmaY,
    const double imageWeight)
{
    cv::Mat inputImageMat = inputImage;

    if (inputImageMat.empty()) {
        throw std::invalid_argument("Input image for deblurring is empty");
    }

    cv::Mat outputImageMat;

    std::vector<cv::Mat> channels;
    cv::split(inputImageMat, channels);

    for (cv::Mat& channel : channels) {
        cv::Mat channelfloat;
        channel.convertTo(channelfloat, CV_32F);
        cv::GaussianBlur(
            channelfloat, channel,
            cv::Size(gaussianKernelSize, gaussianKernelSize),
            sigmaX, sigmaY);
        cv::addWeighted(
            channelfloat, 2.0 * imageWeight,
            channel, 2.0 * imageWeight - 2.0,
            0.0,
            channel);

        // convert back to 8bits gray scale
        channel.convertTo(channel, CV_8U);
    }

    cv::merge(channels, outputImageMat);

    outputImage = outputImageMat;
}
