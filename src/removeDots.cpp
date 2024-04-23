
#include "removeDots.h"

#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void prl::removeDots(const cv::Mat& inputImage, cv::Mat& outputImage, const double radius)
{
    outputImage = inputImage.clone();

    size_t maxDotDiameter = inputImage.cols * 0.01;

    // Converting to grayscale
    cv::Mat gray;
    if (inputImage.channels() == 3) {
        cv::cvtColor(inputImage, gray, cv::COLOR_BGR2GRAY);
    } else {
        gray = inputImage;
    }

    // Configure blob detector
    cv::SimpleBlobDetector::Params params;

    params.filterByArea = true;
    // TODO: calculate coefficient depend on image size
    params.maxArea = CV_PI * maxDotDiameter * maxDotDiameter / 4.0;
    params.minArea = 0;

    params.filterByCircularity = true;
    params.minCircularity = 0.9;
    // params.maxCircularity = 1.0;

    cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params);

    // Detect blobs.
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(gray, keypoints);

    // Border heuristic
    int width = inputImage.cols;
    int height = inputImage.rows;

    int leftX = width * 0.1;
    int rightX = width - leftX;
    int upY = height * 0.1;
    int bottomY = height - upY;

    std::vector<cv::KeyPoint> filteredKeypoints = keypoints;
    /*for(const auto& keypoint : keypoints)
    {
        if(keypoint.pt.x > leftX && keypoint.pt.x < rightX &&
           keypoint.pt.y > upY && keypoint.pt.y < bottomY)
        {
            continue;
        }
        filteredKeypoints.push_back(keypoint);
    }*/
    // End border heuristic

    // Fill keypoits by white color.
    // TODO: maybe we should find automatically background color and use it for filling instead of white
    /*for(const auto& keypoint : filteredKeypoints)
    {
        cv::circle(outputImage, keypoint.pt, keypoint.size / 2.0 + 3, cv::Scalar(255,255,255), cv::FILLED);
    }*/
    cv::drawKeypoints(outputImage, keypoints, outputImage, cv::Scalar(0, 0, 255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
}