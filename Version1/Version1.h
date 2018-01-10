#pragma once

#include <QtWidgets/QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QSlider>
#include <QSpinBox>
#include <QLayout>
#include <QLabel>
#include <iostream>
#include <string>
#include "Translation.h"
//#include "ui_Version1.h"

class Version1 : public QMainWindow
{
	Q_OBJECT

public:
	Version1(QWidget *parent = Q_NULLPTR);
private slots:
	void fileOpenActionSlot();
	void helpOpenActionSlot();
	void openGrayscaleSlot();
	void traslateSlot();
	void saveImageSlot();
private:
	//Ui::Version1Class ui;
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
};
