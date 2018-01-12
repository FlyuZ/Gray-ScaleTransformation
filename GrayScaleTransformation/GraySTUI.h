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
#include <QComboBox>
#include "GrayTo.h"

/**
By NWAFU Flyuz
http://blog.csdn.net/ZHangFFYY/
2018/1/10
��ɽ�����
2018/1/11
���v1.2�汾��������
2018/1/11
���v1.8�汾��ͼƬ��ʾ�����⣬��Ϊqt��ʾ��
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

	QToolBar *selectTool;  //ѡ��ģʽ����
	QComboBox *selectBox;

	void setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor); //���
};
