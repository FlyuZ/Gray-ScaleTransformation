#pragma once

#include <QtWidgets/QMainWindow>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QMessageBox>
#include <QAction>
#include <QToolBar>
#include <QLayout>
#include <QFileDialog>
#include <QGroupBox>
#include "GrayTo.h"

/**
By NWAFU Flyuz
http://blog.csdn.net/ZHangFFYY/
2018/1/10
��ɽ�����
2018/1/11
���v1.0�汾��������
**/

class GrayST : public QMainWindow
{
	Q_OBJECT

public:
	GrayST(QWidget *parent = Q_NULLPTR);
	~GrayST();
	private slots:
	void fileOpenActionSlot(); //��
	void helpOpenActionSlot();
	void openGrayscaleSlot();
	void traslateSlot();
	void saveImageSlot();
private:
	void createAction();  //��������
	void createToolBar(); //��������
	void initWindow();    //��ʼ������
	QString fileFull;     //�򿪵�ͼƬ·��������
	QString fileSuffix;   //�ļ���׺��
	QString filePath;     //�����ļ�ʱ��·��
	cv::Mat srcI;         //�Ҷ�ͼ
	cv::Mat dstI;         //ת�����ͼƬ

	QSpinBox *spinA;      //�����ͻ���
	QSpinBox *spinB;
	QSpinBox *spinC;
	QSpinBox *spinD;
	QSlider *sliderA;
	QSlider *sliderB;
	QSlider *sliderC;
	QSlider *sliderD;
	QLabel *labelA;
	QLabel *labelB;
	QLabel *labelC;
	QLabel *labelD;
	int a = 0, b = 0, c = 0, d = 0;      //����

	QAction *fileOpenAction;       //���ļ�����
	QAction *helpOpenAction;       //�򿪰�������
	QAction *openGrayscaleAction;  //�򿪻Ҷ�ͼ����
	QAction *traslateAction;       //��ת�����ͼƬ
	QAction *saveImageAction;      //����ת�����ͼƬ

	QToolBar *fileTool;        //ѡ���ļ�����
	QToolBar *helpTool;        //��������
	QToolBar *grayscaleTool;   //�򿪻Ҷ�ͼ����
	QToolBar *traslateTool;    //ת������
	QToolBar *saveImageTool;   //����ͼƬ����

	void setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor); //���
};
