
#include "rotate.h"

#include <cmath>

#include <opencv2/imgproc/imgproc.hpp>

#include "utils.h"

namespace prl {
void rotate(const cv::Mat& inputImage, cv::Mat& outputImage, double angle)
{
    angle = std::fmod(angle, 360.0);
    if (eq_d(angle, 90.0)) {
        // rotate on 90
        cv::transpose(inputImage, outputImage);
        cv::flip(outputImage, outputImage, 1);
        return;
    } else if (eq_d(angle, 180.0)) {
        // rotate on 180
        cv::flip(inputImage, outputImage, -1);
        return;
    } else if (eq_d(angle, 270.0)) {
        // rotate on 270
        cv::transpose(inputImage, outputImage);
        cv::flip(outputImage, outputImage, 0);
        return;
    } else {
        outputImage = inputImage.clone();
        cv::bitwise_not(inputImage, inputImage);

        int len = std::max(outputImage.cols, outputImage.rows);
        cv::Point2f pt(static_cast<float>(len / 2.0), static_cast<float>(len / 2.0));
        cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);

        cv::warpAffine(inputImage, outputImage, r, cv::Size(len, len));

        cv::bitwise_not(inputImage, inputImage);
        cv::bitwise_not(outputImage, outputImage);
    }
}
}