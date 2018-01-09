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
	void createAction();  //��������
	void createMenu();     //�����˵�
	void createToolBar();   //��������
	void initWindow();
	QSpinBox *spinA; //�����ͻ���
	QSpinBox *spinB;
	QSpinBox *spinC;
	QSpinBox *spinD;
	QSlider *sliderA;
	QSlider *sliderB;
	QSlider *sliderC;
	QSlider *sliderD;

	QAction *fileOpenAction;  //���ļ�����
	QAction *helpOpenAction;  //�򿪰�������
	QMenu *fileMenu;  //�˵��ļ�
	QMenu *helpMenu;  //�����˵�
	QToolBar *fileTool; //ѡ���ļ�����
	QToolBar *helpTool; //��������
};
