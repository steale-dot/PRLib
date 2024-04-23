
#include "resize.h"

#include <opencv2/imgproc/imgproc.hpp>

void prl::resize(const cv::Mat& src, cv::Mat& dst, int scaleX, int scaleY, int maxSize)
{
    cv::Size newImageSize;

    if (scaleX > 0 && scaleY > 0) {
        newImageSize = cv::Size(
            static_cast<int>(src.cols * scaleX),
            static_cast<int>(src.rows * scaleY));

        cv::resize(src, dst, newImageSize, 0, 0, cv::INTER_AREA);
    } else {
        int longSide = std::max(src.cols, src.rows);

        int scaleFactorX = 1;
        int scaleFactorY = 1;

        dst = src.clone();

        while (longSide > maxSize) {
            cv::pyrDown(dst, dst);

            longSide = std::max(dst.cols, dst.rows);
            scaleFactorX *= 2;
            scaleFactorY *= 2;
        }

        newImageSize = cv::Size(src.cols / scaleFactorX, src.rows / scaleFactorY);
    }
}