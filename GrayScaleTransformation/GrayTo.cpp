#include "GrayTo.h"
/**
By NWAFU Flyuz
http://blog.csdn.net/ZHangFFYY/
**/

cv::Mat readFile(std::string fileName)
{
	cv::Mat srcImage = cv::imread(fileName, 0);

	return srcImage;
}

bool saveMat(cv::Mat dstI, std::string Path, std::string Suffix, int a, int b, int c, int d)
{
	std::stringstream ss;
	std::string Full;
	ss << Path << "/" << a << "-" << b << "-" << c << "-" << d << "." << Suffix;
	ss >> Full;

	if (imwrite(Full, dstI))
		return true;
	else
		return false;
}

cv::Mat PieGrayTo(cv::Mat srcIm, int a, int b, int c, int d)
{
	cv::Mat dstImage;
	dstImage = srcIm;
	int rowsNum = dstImage.rows;
	int colsNum = dstImage.cols;
	//图像连续性判断
	if (dstImage.isContinuous())
	{
		colsNum = colsNum * rowsNum;
		rowsNum = 1;
	}
	//图像指针操作
	uchar *pDataMat;
	//进行对比度拉伸
	for (int j=0; j<rowsNum; j++)
	{
		pDataMat = dstImage.ptr<uchar>(j);
		for (int i=0; i<colsNum; i++)
		{
			if (pDataMat[i] < a)
			{
				pDataMat[i] = pDataMat[i] * c / a;
			}
			else if (pDataMat[i] > b)
			{
				pDataMat[i] = (pDataMat[i] - b) * (255 - d) / (255 - b) + d;
			}
			else
			{
				pDataMat[i] = (pDataMat[i] - a) * (d - c) / (b - a) + c;
			}
		}
	}
	return dstImage;
}


cv::Mat LogGrayTo(cv::Mat srcIm, int a)
{
	cv::Mat dstImage;
	//首先进行图像类型转换  
	srcIm.convertTo(dstImage, CV_32F);
	//图像矩阵元素进行加1操作  
	dstImage = dstImage + 1;
	//图像对数操作  
	cv::log(dstImage, dstImage);
	dstImage = a * dstImage;
	//图像进行归一化操作  
	normalize(dstImage, dstImage, 0, 255, cv::NORM_MINMAX);
	convertScaleAbs(dstImage, dstImage);
	return dstImage;
}