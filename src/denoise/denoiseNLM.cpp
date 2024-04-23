
#include "denoiseNLM.h"

#include <opencv2/photo/photo.hpp>

void prl::denoise(const cv::Mat& inputImage, cv::Mat& outputImage, double strength)
{
    cv::fastNlMeansDenoisingColored(inputImage, outputImage, strength);
}