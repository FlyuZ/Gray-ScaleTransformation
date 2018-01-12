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
	//ͼ���������ж�
	if (dstImage.isContinuous())
	{
		colsNum = colsNum * rowsNum;
		rowsNum = 1;
	}
	//ͼ��ָ�����
	uchar *pDataMat;
	//���жԱȶ�����
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
	//���Ƚ���ͼ������ת��  
	srcIm.convertTo(dstImage, CV_32F);
	//ͼ�����Ԫ�ؽ��м�1����  
	dstImage = dstImage + 1;
	//ͼ���������  
	cv::log(dstImage, dstImage);
	dstImage = a * dstImage;
	//ͼ����й�һ������  
	normalize(dstImage, dstImage, 0, 255, cv::NORM_MINMAX);
	convertScaleAbs(dstImage, dstImage);
	return dstImage;
}