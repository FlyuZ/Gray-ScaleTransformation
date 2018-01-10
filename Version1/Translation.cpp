#include "Translation.h"

/**
By NWAFU Flyuz
http://blog.csdn.net/ZHangFFYY/
2018/1/10
**/

cv::Mat readFile(std::string fileName)
{
	cv::Mat srcImage = cv::imread(fileName, 0);

	imshow("灰度图", srcImage);
	return srcImage;
}

cv::Mat GrayTo(cv::Mat srcI, int a, int b, int c, int d)
{
	cv::Mat dstImage(srcI);
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
	imshow("转换后灰度图", dstImage);
	return dstImage;
}

bool saveMat(cv::Mat dstI, std::string Path, std::string Suffix, int a, int b, int c, int d)
{
	std::stringstream ss;
	std::string Full;
	ss << Path << "/"<< a << "-" << b << "-" << c << "-" << d << "." << Suffix;
	ss >> Full;
	
	if (imwrite(Full, dstI))
		return true;
	else
		return false;
}