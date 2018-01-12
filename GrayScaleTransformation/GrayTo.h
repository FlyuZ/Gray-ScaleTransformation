#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <string>
#include <sstream>

/**
By NWAFU Flyuz
http://blog.csdn.net/ZHangFFYY/
2018/1/10
��ɷֶ����Ա任����
2018/1/11
��ɶ����任����
2018/1/12
�޸ı���ͼƬ����
**/


cv::Mat readFile(std::string fileName);
std::string savePieMat(cv::Mat dstI, std::string Path, std::string Suffix, int a, int b, int c, int d);
std::string saveLogMat(cv::Mat dstI, std::string Path, std::string Suffix, int e);

cv::Mat PieGrayTo(cv::Mat srcI, int a, int b, int c, int d);
cv::Mat LogGrayTo(cv::Mat srcI, int a);