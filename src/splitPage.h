
#ifndef PRLIB_SPLITPAGE_H
#define PRLIB_SPLITPAGE_H

#include <opencv2/core/core.hpp>

namespace prl
{
/*!
 * \brief Find border between two pages.
 * \param[in] inputImage Input image.
 * \details Try to find vertical line on the image.
 * Should be used if you have image with two pages.
 */
CV_EXPORTS std::pair<cv::Point, cv::Point> findVertLine(const cv::Mat& inputImage);
}

#endif //PRLIB_SPLITPAGE_H
