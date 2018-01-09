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
	void createAction();  //创建动作
	void createMenu();    //创建菜单
	void createToolBar(); //创建工具
	void initWindow();    //初始化界面
	QString fileName;
	cv::Mat srcI;
	cv::Mat disI;

	QSpinBox *spinA; //输出框和滑竿
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

	QAction *fileOpenAction;  //打开文件动作
	QAction *helpOpenAction;  //打开帮助动作
	QAction *openGrayscaleAction; //打开灰度图动作
	QAction *traslateAction;  //打开转换后的图片

	QMenu *fileMenu;  //菜单文件
	QMenu *helpMenu;  //帮助菜单
	QToolBar *fileTool; //选择文件工具
	QToolBar *helpTool; //帮助工具
	QToolBar *grayscaleTool; //打开灰度图工作
	QToolBar *traslateTool;
};
