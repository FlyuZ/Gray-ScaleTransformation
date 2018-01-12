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
完成界面框架
2018/1/11
完成v1.2版本基本功能
2018/1/11
完成v1.8版本，图片显示有问题，改为qt显示。
**/

class GrayST : public QMainWindow
{
	Q_OBJECT

public:
	GrayST(QWidget *parent = Q_NULLPTR);
	~GrayST();
	private slots:
	void fileOpenActionSlot(); //槽
	void helpOpenActionSlot();
	void openGrayscaleSlot();
	void traslateSlot();
	void saveImageSlot();
private:
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

	QToolBar *selectTool;  //选择模式工具
	QComboBox *selectBox;

	void setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor); //玩的
};
