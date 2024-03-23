#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

/**
 * @brief Функция, применяющая установку бинарного порога к картинке
 * 
 * @param Исходная картинка
 * @param Обработанная картинка
*/
void thresh_binary(cv::Mat src, cv::Mat dst){
    cv::threshold(src,dst, 0, 255, cv::THRESH_BINARY); 
    cv::imwrite("../opencv-threshold-example.jpg", dst); 
    cv::imshow("Image", dst);
    cv::waitKey();
}
/**
 * @brief Функция, применяющая установку бинарного порога с инверсией к картинке
 * 
 * @param Исходная картинка
 * @param Обработанная картинка
*/
void thresh_binary_inv(cv::Mat src, cv::Mat dst){
    cv::threshold(src,dst, 0, 255, cv::THRESH_BINARY_INV); 
    cv::imwrite("../opencv-threshold-example.jpg", dst); 
    cv::imshow("Image", dst);
    cv::waitKey();
}
/**
 * @brief Функция, применяющая установку заданного порога к картинке
 * 
 * @param Исходная картинка
 * @param Обработанная картинка
 * @param Порог
 * @param Маскимальное значение
*/
void thresh_trunc(cv::Mat src, cv::Mat dst, double thresh, double maxValue){
    cv::threshold(src,dst, thresh, maxValue, cv::THRESH_TRUNC);
    cv::imwrite("../opencv-threshold-example.jpg", dst); 
    cv::imshow("Image", dst);
    cv::waitKey();
}
/**
 * @brief Функция, применяющая установку нулевого порога к картинке
 * 
 * @param Исходная картинка
 * @param Обработанная картинка
 * @param Порог
 * @param Маскимальное значение
*/
void thresh_torezo(cv::Mat src, cv::Mat dst, double thresh, double maxValue){
    cv::threshold(src,dst, thresh, maxValue, cv::THRESH_TOZERO); 
    cv::imwrite("../opencv-threshold-example.jpg", dst); 
    cv::imshow("Image", dst);
    cv::waitKey();
}
/**
 * @brief Функция, применяющая установку нулевого порога с инверсией к картинке
 * 
 * @param Исходная картинка
 * @param Обработанная картинка
*/
void thresh_torezo_inv(cv::Mat src, cv::Mat dst, double thresh, double maxValue){
    cv::threshold(src,dst, thresh, maxValue, cv::THRESH_TOZERO_INV); 
    cv::imwrite("../opencv-threshold-example.jpg", dst); 
    cv::imshow("Image", dst);
    cv::waitKey();
}

int main() {
    cv::Mat src = cv::imread("C:/vscodexe/test/cool_mf_numbers.png", cv::IMREAD_GRAYSCALE);
    cv::Mat dst;

    double thresh = 64;
    double maxValue = 196; 

    thresh_binary(src, dst);
    thresh_binary_inv(src, dst);
    thresh_trunc(src, dst, thresh, maxValue);
    thresh_torezo(src, dst, thresh, maxValue);
    thresh_torezo_inv(src, dst, thresh, maxValue);

    return 0;
}
