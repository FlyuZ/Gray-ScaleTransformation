#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <string>
#include <sstream>
#include <iostream>
cv::Mat readFile(std::string fileName);
cv::Mat GrayTo(cv::Mat srcI, int a, int b, int c, int d);
bool saveMat(cv::Mat dstI, std::string Path, std::string Suffix, int a, int b, int c, int d);