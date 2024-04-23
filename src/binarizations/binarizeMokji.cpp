
#include <array>
#include <stdexcept>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace prl {

void binarizeMokji(const cv::Mat& inputImage, cv::Mat& outputImage,
    size_t maxEdgeWidth, size_t minEdgeMagnitude)
{
    if (maxEdgeWidth < 1) {
        throw std::invalid_argument("mokjiThreshold: invalid maxEdgeWidth");
    }
    if (minEdgeMagnitude < 1) {
        throw std::invalid_argument("mokjiThreshold: invalid minEdgeMagnitude");
    }

    cv::Mat gray;
    cv::cvtColor(inputImage, gray, cv::COLOR_BGR2GRAY);

    const size_t dilateSize = (maxEdgeWidth + 1) * 2 - 1;

    cv::Mat dilatedImage;
    cv::dilate(gray, dilatedImage, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(dilateSize, dilateSize)));

    std::array<std::array<size_t, 256>, 256> matrix;

    const int w = inputImage.cols;
    const int h = inputImage.rows;

    for (int y = maxEdgeWidth; y < h - static_cast<int>(maxEdgeWidth); ++y) {
        for (int x = maxEdgeWidth; x < w - static_cast<int>(maxEdgeWidth); ++x) {
            const size_t pixel = gray.at<uchar>(cv::Point(x, y));
            const size_t darkestNeighbour = dilatedImage.at<uchar>(cv::Point(x, y));

            assert(darkestNeighbour >= pixel);

            ++matrix[darkestNeighbour][pixel];
        }
    }

    size_t nominator = 0;
    size_t denominator = 0;
    for (size_t m = 0; m < 256 - minEdgeMagnitude; ++m) {
        for (size_t n = m + minEdgeMagnitude; n < 256; ++n) {
            assert(n >= m);

            const size_t val = matrix[n][m];
            nominator += (m + n) * val;
            denominator += val;
        }
    }

    if (denominator == 0) {
        cv::threshold(gray, outputImage, 128, 255, cv::THRESH_BINARY);
    }

    const int threshold = 0.5 * nominator / denominator + 0.5;
    cv::threshold(gray, outputImage, threshold, 255, cv::THRESH_BINARY);
}

}
