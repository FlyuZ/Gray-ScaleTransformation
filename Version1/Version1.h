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
#include <QDebug>
#include <iostream>
#include <string>
#include "ui_Version1.h"

class Version1 : public QMainWindow
{
	Q_OBJECT

public:
	Version1(QWidget *parent = Q_NULLPTR);
private slots:
	void fileOpenActionSlot();
	void helpOpenActionSlot();
private:
	Ui::Version1Class ui;
	void createAction();  //创建动作
	void createMenu();     //创建菜单
	void createToolBar();   //创建工具
	void initWindow();
	QSpinBox *spinA; //输出框和滑竿
	QSpinBox *spinB;
	QSpinBox *spinC;
	QSpinBox *spinD;
	QSlider *sliderA;
	QSlider *sliderB;
	QSlider *sliderC;
	QSlider *sliderD;

	QAction *fileOpenAction;  //打开文件动作
	QAction *helpOpenAction;  //打开帮助动作
	QMenu *fileMenu;  //菜单文件
	QMenu *helpMenu;  //帮助菜单
	QToolBar *fileTool; //选择文件工具
	QToolBar *helpTool; //帮助工具
};
