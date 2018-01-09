#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QSlider>
#include <QSpinBox>
#include <QLayout>
#include <QLabel>
#include <QDebug>
#include <iostream>
#include <string>
#include <opencv2\core\core.hpp>
#include "ui_Version1.h"

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
private:
	//Ui::Version1Class ui;
	void createAction();  //��������
	void createMenu();    //�����˵�
	void createToolBar(); //��������
	void initWindow();    //��ʼ������
	QString fileName;
	cv::Mat srcI;
	cv::Mat disI;

	QSpinBox *spinA; //�����ͻ���
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

	QAction *fileOpenAction;  //���ļ�����
	QAction *helpOpenAction;  //�򿪰�������
	QAction *openGrayscaleAction; //�򿪻Ҷ�ͼ����
	QAction *traslateAction;  //��ת�����ͼƬ

	QMenu *fileMenu;  //�˵��ļ�
	QMenu *helpMenu;  //�����˵�
	QToolBar *fileTool; //ѡ���ļ�����
	QToolBar *helpTool; //��������
	QToolBar *grayscaleTool; //�򿪻Ҷ�ͼ����
	QToolBar *traslateTool;
};
