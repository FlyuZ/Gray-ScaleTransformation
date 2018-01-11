#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <string>
#include <sstream>

/**
By NWAFU Flyuz
http://blog.csdn.net/ZHangFFYY/
2018/1/10
完成分段线性变换函数
2018/1/11
完成分层变换函数、对数变换函数
**/


cv::Mat readFile(std::string fileName);
bool saveMat(cv::Mat dstI, std::string Path, std::string Suffix, int a, int b, int c, int d);

cv::Mat PieGrayTo(cv::Mat srcI, int a, int b, int c, int d);
cv::Mat SliGrayTo(cv::Mat srcI, int a);
cv::Mat LogGrayTo(cv::Mat srcI, int a);