
#ifndef PRLIB_SCANNED_DOCUMENT_IMAGE_AUTO_CROP_H_
#define PRLIB_SCANNED_DOCUMENT_IMAGE_AUTO_CROP_H_

#include <opencv2/core/core.hpp>

#include <vector>

namespace prl
{
/*!
 * \brief Find document contour.
 * \param[in] inputImage Input image.
 * \param[in] scaleX Horizontal scale factor.
 * \param[in] scaleY Vertical scale factor.
 * \param[out] resultContour Contour of a document.
 * \return true if contour exists, false otherwise.
 */
CV_EXPORTS bool documentContour(
        cv::Mat& inputImage,
        const double scaleX, const double scaleY,
        std::vector<cv::Point2f>& resultContour);

/*!
 * \brief Crop scanned document automatically.
 * \param[in] inputImage Input image.
 * \param[out] outputImage Cropped image.
 * \return true if image cropped.
 */
CV_EXPORTS bool autoCrop(cv::Mat& inputImage, cv::Mat& outputImage);

}
#endif // PRLIB_SCANNED_DOCUMENT_IMAGE_AUTO_CROP_H_
