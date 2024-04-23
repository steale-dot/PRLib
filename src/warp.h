
#ifndef PRLIB_WARP
#define PRLIB_WARP

#include <opencv2/core/core.hpp>

namespace prl
{

/*!
 * \brief Transform image to crop document.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \param[in] x0 Top left x coordinate.
 * \param[in] y0 Top left y coordinate.
 * \param[in] x1 Top right x coordinate.
 * \param[in] y1 Top right y coordinate.
 * \param[in] x2 Bottom right x coordinate.
 * \param[in] y2 Bottom right y coordinate.
 * \param[in] x3 Bottom left x coordinate.
 * \param[in] y3 Bottom left y coordinate.
 * \param[in] ratio Expected Height/Width ratio
 * \details Crop image and do warp transformation to rectangle.
 * Calculates aspect ratio of source image and keeps it after crop.
 */
CV_EXPORTS void warpCrop(const cv::Mat& inputImage,
              cv::Mat& outputImage,
              const int x0, const int y0,
              const int x1, const int y1,
              const int x2, const int y2,
              const int x3, const int y3,
              double ratio = -1.0,
              const int borderMode = cv::BORDER_CONSTANT,
              const cv::Scalar& borderValue = cv::Scalar());


/*!
 * \brief Transform image to crop document.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Output image.
 * \param[in] points Document contour.
 * \param[in] ratio Expected Height/Width ratio
 * \details Crop image and do warp transformation to rectangle.
 * Calculates aspect ratio of source image and keeps it after crop.
 */
CV_EXPORTS void warpCrop(cv::Mat& inputImage, cv::Mat& outputImage,
              const std::vector<cv::Point>& points,
              double ratio = -1.0,
              int borderMode = cv::BORDER_CONSTANT,
              const cv::Scalar& borderValue = cv::Scalar());
}

#endif //PRLIB_WARP
