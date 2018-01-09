#include "Translation.h"


cv::Mat readFile(std::string fileName)
{
	cv::Mat srcImage = cv::imread(fileName, 0);

	if (!srcImage.data)
	{
		//return 0;
	}
	imshow("�Ҷ�ͼ", srcImage);
	return srcImage;
}

cv::Mat GrayTo(cv::Mat srcI, int a, int b, int c, int d)
{
	cv::Mat dstImage(srcI);
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
	for (int j = 0; j<rowsNum; j++)
	{
		pDataMat = dstImage.ptr<uchar>(j);
		for (int i = 0; i<colsNum; i++)
		{
			if (pDataMat[i] < a) {
				pDataMat[i] = pDataMat[i] * c / a;
			}
			else if (pDataMat[i] > b) {
				pDataMat[i] = (pDataMat[i] - b) * (255 - d) / (255 - b) + d;
			}
			else
				pDataMat[i] = (pDataMat[i] - a) * (d - c) / (b - a) + c;
		}
	}
	imshow("ת����Ҷ�ͼ", dstImage);
	return dstImage;
}