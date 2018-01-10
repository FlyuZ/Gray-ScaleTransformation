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
	void createAction();  //创建动作
	void createToolBar(); //创建工具
	void initWindow();    //初始化界面
	QString fileFull;     //打开的图片路径及名称
	QString fileSuffix;   //文件后缀名
	QString filePath;     //保存文件时的路径
	cv::Mat srcI;         //灰度图
	cv::Mat dstI;         //转换后的图片

	QSpinBox *spinA;      //输出框和滑竿
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
	int a = 0, b = 0, c = 0, d = 0;      //参数

	QAction *fileOpenAction;       //打开文件动作
	QAction *helpOpenAction;       //打开帮助动作
	QAction *openGrayscaleAction;  //打开灰度图动作
	QAction *traslateAction;       //打开转换后的图片
	QAction *saveImageAction;      //保存转换后的图片

	QToolBar *fileTool;        //选择文件工具
	QToolBar *helpTool;        //帮助工具
	QToolBar *grayscaleTool;   //打开灰度图工具
	QToolBar *traslateTool;    //转换工具
	QToolBar *saveImageTool;   //保存图片功能
};
