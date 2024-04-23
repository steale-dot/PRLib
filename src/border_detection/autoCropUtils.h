
#ifndef PRLIB_SCANNED_DOCUMENT_IMAGE_BORDER_DETECTION_UTILS_H
#define PRLIB_SCANNED_DOCUMENT_IMAGE_BORDER_DETECTION_UTILS_H

#include <vector>

#include <opencv2/core/core.hpp>

/*!
 * \def GOOD_RECTANGLE
 * \brief Code of correct rectangle.
 */
#define GOOD_RECTANGLE (0)

/*!
 * \def BAD_RECTANGLE
 * \brief Code of incorrect rectangle.
 */
#define BAD_RECTANGLE (-1)

/*!
 * \typedef MarkerRectangle
 * \struct tag_MarkerRectangle
 * \brief Detected marker rectangle.
 */
typedef struct tag_MarkerRectangle
{
    /** Outer corners positions of rectangle. */
    cv::Point2f outerCorners[4];
    /** Outer degrees values. */
    double outerDegrees[4];

} MarkerRectangle;

//! Get angle between vectors.
double dotDegree(cv::Point& common, cv::Point& a, cv::Point& b);

/*!
 * \brief Check rectangle
 * \param[in] contour Contour.
 * \param[out] rectangle Resulted rectangle.
 * \return if contour is rectangle then GOOD_RECTANGLE else BAD_RECTANGLE.
 */
int CheckRectangle(
        std::vector<cv::Point>& contour,
        MarkerRectangle* rectangle);

/*!
 * \brief Try to detect document contour.
 * \param[in] source Binary image.
 * \param[out] resultContour Resulted document contour.
 * \return true if contour detected.
 */
bool findDocumentContour(
        cv::Mat& source,
        std::vector<cv::Point2f>& resultContour);

/*!
 * \brief Binarization on base of local variance estimation.
 * \param image Input image.
 * \param result Binarized image.
 */
void binarizeByLocalVariances(cv::Mat& image, cv::Mat& result);
//void binarizeByLocalVariances_without_filters(cv::Mat &image, cv::Mat &result);

bool isQuadrangle(const std::vector<cv::Point>& contour);


void scaleContour(std::vector<cv::Point2f>& contour, cv::Size& fromImageSize, cv::Size& toImageSize);

/*!
 * \brief Contour points ordering.
 * \param[inout] contour Contour.
 * \return true if ordering is successful.
 * \note Implementation of this function is based on
 * <a href="https://www.pyimagesearch.com/2014/08/25/4-point-opencv-getperspective-transform-example/">Pyimagesearch</a>.
 */
bool cropVerticesOrdering(std::vector<cv::Point2f>& contour);

bool intersection(cv::Point2f o1, cv::Point2f p1, cv::Point2f o2, cv::Point2f p2,
                  cv::Point2f& r);

#endif // PRLIB_SCANNED_DOCUMENT_IMAGE_BORDER_DETECTION_UTILS_H
