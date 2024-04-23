
#include "splitPage.h"
#include "deskew.h"
#include "imageLibCommon.h"

#include <algorithm>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// PLEASE DON'T USE IT SINCE IT'S WIP!
std::pair<cv::Point, cv::Point> findVertLine(const cv::Mat& inputImage)
{

    cv::Mat imageToProc = inputImage.clone();
    if (inputImage.channels() == 3) {
        cv::cvtColor(inputImage, imageToProc, cv::COLOR_BGR2GRAY);
    }
    // TODO: Should be possibly resized to smth like 256px

    // TODO: can be wrong in the reason of difficult for analyze page
    prl::deskew(inputImage, imageToProc);

    // TODO: check binarizeByVariance edge detection
    cv::Mat resultCanny;
    double upper = 50;
    double lower = 25;
    cv::Canny(imageToProc, resultCanny, lower, upper);

    // Use HoughLine detection for finding all lines
    std::vector<cv::Vec2f> lines, vertLines;
    const int thresholdHough = 50;
    cv::HoughLines(resultCanny, lines, 1, CV_PI / 180.0, thresholdHough, 0, 0);

    // Extract all vertical lines
    for (size_t i = 0; i < lines.size(); ++i) {
        float theta = lines[i][1];
        if (theta > CV_PI / 180.0 * 170.0 || theta < CV_PI / 180.0 * 10.0) {
            vertLines.push_back(lines[i]);
        }
    }

    // TODO: delete similar lines. Is it required?
    // deleteSimilarLines()

    // Find the nearest line to the center
    int center = resultCanny.cols / 2;
    for (const auto& line : vertLines) {
        auto lineByPoint = fromVec2f(line);
    }

    return std::make_pair(cv::Point(0, 0), cv::Point(0, 0));
};
