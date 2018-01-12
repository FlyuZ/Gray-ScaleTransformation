#include "GraySTui.h"

/**
By NWAFU Flyuz
http://blog.csdn.net/ZHangFFYY/
**/

GrayST::GrayST(QWidget *parent)
	: QMainWindow(parent)
{
	createAction();
	createToolBar();
	initWindow();
	this->setWindowOpacity(0.9); //窗口整体透明度，0-1 从全透明到不透明  
}
GrayST::~GrayST()
{
}

void GrayST::createAction()
{
	//创建打开文件动作  关联信号和槽
	QString fileSel = QString::fromLocal8Bit("选择一张图片");
	fileOpenAction = new QAction(QIcon(":/GrayST/Resources/1.png"), fileSel, this);
	connect(fileOpenAction, &QAction::triggered, this, &GrayST::fileOpenActionSlot);
	//创建打开灰度图动作  关联
	QString openGrayStr = QString::fromLocal8Bit("打开灰度图");
	openGrayscaleAction = new QAction(QIcon(":/GrayST/Resources/2.png"), openGrayStr, this);
	connect(openGrayscaleAction, &QAction::triggered, this, &GrayST::openGrayscaleSlot);
	//创建灰度转换动作   关联
	QString traStr = QString::fromLocal8Bit("灰度变换");
	traslateAction = new QAction(QIcon(":/GrayST/Resources/3.png"), traStr, this);
	connect(traslateAction, &QAction::triggered, this, &GrayST::traslateSlot);
	//创建保存图片动作  关联
	QString saveStr = QString::fromLocal8Bit("保存变换后的图片");
	saveImageAction = new QAction(QIcon(":/GrayST/Resources/4.png"), saveStr, this);
	connect(saveImageAction, &QAction::triggered, this, &GrayST::saveImageSlot);
	//创建打开帮助文档动作  关联
	QString helpStr = QString::fromLocal8Bit("打开帮助");
	helpOpenAction = new QAction(QIcon(":/GrayST/Resources/5.png"), helpStr, this);
	connect(helpOpenAction, &QAction::triggered, this, &GrayST::helpOpenActionSlot);
	//关联下拉菜单

}


void GrayST::createToolBar()
{
	//初始化文件工具
	fileTool = addToolBar("File");
	fileTool->addAction(fileOpenAction);

	//初始化打开灰度图工具
	grayscaleTool = addToolBar("Open GrayScale");
	grayscaleTool->addAction(openGrayscaleAction);

	//初始化转换工具
	traslateTool = addToolBar("Traslate");
	traslateTool->addAction(traslateAction);

	//初始化保存工具
	saveImageTool = addToolBar("save");
	saveImageTool->addAction(saveImageAction);

	//创建帮助工具
	helpTool = addToolBar("Help");
	helpTool->addAction(helpOpenAction);

	selectTool = addToolBar("select");
	selectBox = new QComboBox();
	QString sel1 = QString::fromLocal8Bit("分段线性变换");
	QString sel2 = QString::fromLocal8Bit("对数变换");
	selectBox->addItem(QIcon(":/GrayST/Resources/7.png"), sel1);
	selectBox->addItem(QIcon(":/GrayST/Resources/7.png"), sel2);
	selectTool->addWidget(selectBox);

}

void  GrayST::initWindow()
{
	spinA = new QSpinBox(this);
	sliderA = new QSlider(Qt::Horizontal, this);
	spinB = new QSpinBox(this);
	sliderB = new QSlider(Qt::Horizontal, this);
	spinC = new QSpinBox(this);
	sliderC = new QSlider(Qt::Horizontal, this);
	spinD = new QSpinBox(this);
	sliderD = new QSlider(Qt::Horizontal, this);
	spinE = new QSpinBox(this);
	sliderE = new QSlider(Qt::Horizontal, this);

	spinA->setRange(0, 255); //设置数字范围
	spinB->setRange(0, 255);
	spinC->setRange(0, 255);
	spinD->setRange(0, 255);
	spinE->setRange(0, 255);
	sliderA->setRange(0, 255);
	sliderB->setRange(0, 255);
	sliderC->setRange(0, 255);
	sliderD->setRange(0, 255);
	sliderE->setRange(0, 255);
	setSliderQss(sliderA, "#E8EDF2", "#E74C3C", "#E74C3C");
	setSliderQss(sliderB, "#E8EDF2", "#E74C3C", "#E74C3C");
	setSliderQss(sliderC, "#E8EDF2", "#E74C3C", "#E74C3C");
	setSliderQss(sliderD, "#E8EDF2", "#E74C3C", "#E74C3C");
	setSliderQss(sliderE, "#E8EDF2", "#E74C3C", "#E74C3C");

	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	//关联QSpinBox和QSlider
	QObject::connect(sliderA, &QSlider::valueChanged, spinA, &QSpinBox::setValue);
	QObject::connect(spinA, spinBoxSignal, sliderA, &QSlider::setValue);
	spinA->setValue(0);
	QObject::connect(sliderB, &QSlider::valueChanged, spinB, &QSpinBox::setValue);
	QObject::connect(spinB, spinBoxSignal, sliderB, &QSlider::setValue);
	spinB->setValue(0);
	QObject::connect(sliderC, &QSlider::valueChanged, spinC, &QSpinBox::setValue);
	QObject::connect(spinC, spinBoxSignal, sliderC, &QSlider::setValue);
	spinC->setValue(0);
	QObject::connect(sliderD, &QSlider::valueChanged, spinD, &QSpinBox::setValue);
	QObject::connect(spinD, spinBoxSignal, sliderD, &QSlider::setValue);
	spinD->setValue(0);
	QObject::connect(sliderE, &QSlider::valueChanged, spinE, &QSpinBox::setValue);
	QObject::connect(spinE, spinBoxSignal, sliderE, &QSlider::setValue);
	spinE->setValue(0);

	QGroupBox *groupA = new QGroupBox(tr("Parameter A"));
	QGroupBox *groupB = new QGroupBox(tr("Parameter B"));
	QGroupBox *groupC = new QGroupBox(tr("Parameter C"));
	QGroupBox *groupD = new QGroupBox(tr("Parameter D"));
	QGroupBox *groupE = new QGroupBox(tr("Parameter E"));
	QHBoxLayout *hboxA = new QHBoxLayout;
	QHBoxLayout *hboxB = new QHBoxLayout;
	QHBoxLayout *hboxC = new QHBoxLayout;
	QHBoxLayout *hboxD = new QHBoxLayout;
	QHBoxLayout *hboxE = new QHBoxLayout;

	hboxA->addWidget(spinA,1);
	hboxA->addWidget(sliderA,5);
	hboxA->setSpacing(20);
	hboxA->setMargin(15);

	hboxB->addWidget(spinB,1);
	hboxB->addWidget(sliderB,5);
	hboxB->setSpacing(20);
	hboxB->setMargin(15);

	hboxC->addWidget(spinC,1);
	hboxC->addWidget(sliderC,5);
	hboxC->setSpacing(20);
	hboxC->setMargin(15);

	hboxD->addWidget(spinD,1);
	hboxD->addWidget(sliderD,5);
	hboxD->setSpacing(20);
	hboxD->setMargin(15);

	hboxE->addWidget(spinE, 1);
	hboxE->addWidget(sliderE, 5);
	hboxE->setSpacing(20);
	hboxE->setMargin(15);

	groupA->setLayout(hboxA);
	groupB->setLayout(hboxB);
	groupC->setLayout(hboxC);
	groupD->setLayout(hboxD);
	groupE->setLayout(hboxE);


	QWidget *widget = new QWidget(this);
	this->setCentralWidget(widget);
	widget->setStyleSheet("background-color:white;");

	QVBoxLayout *hbox = new QVBoxLayout();
	hbox->addWidget(groupA);
	hbox->addWidget(groupB);
	hbox->addWidget(groupC);
	hbox->addWidget(groupD);
	hbox->addWidget(groupE);
	widget->setLayout(hbox);
}


void  GrayST::fileOpenActionSlot()
{
	//定义文件对话框类  
	QFileDialog *fileDialog = new QFileDialog(this);
	//定义文件对话框标题  
	fileDialog->setWindowTitle(tr("Open Image"));
	//设置默认文件路径  
	fileDialog->setDirectory(".");
	//设置文件过滤器  
	fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
	//设置只能选择一个文件QFileDialog::ExistingFiles  
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	//设置视图模式  
	fileDialog->setViewMode(QFileDialog::Detail);

	if (fileDialog->exec())
	{
		fileFull = fileDialog->selectedFiles()[0];
		QFileInfo fileInfo = QFileInfo(fileFull);
		filePath = fileInfo.absolutePath();
		fileSuffix = fileInfo.suffix();
	}
}

void GrayST::helpOpenActionSlot()
{
	std::string helpStr("请先点击选择图片，点击将原图转换成灰度图\n再选择模式和调节参数，然后显示变换后的图片并保存\n设置A,B,C,D的值，用分段函数对任一灰度区间进行扩展或压缩。\n设置E的值，用对数函数对灰度区间进行非线性变换\n作者：Flyuz  QQ：522893161");
	QString helpText = QString::fromLocal8Bit(helpStr.data());
	QMessageBox::information(this, "Help", helpText, QMessageBox::Ok);//下个版本添加图标~
}

void GrayST::openGrayscaleSlot()
{
	if (fileFull.isEmpty())
	{
		std::string infoStr("请先选择图片");
		QString infoText = QString::fromLocal8Bit(infoStr.data());
		QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
	}
	else
	{
		srcI = readFile(fileFull.toStdString());
		imshow("灰度图",srcI);
	}
}

void GrayST::traslateSlot()
{
	a = spinA->value();
	b = spinB->value();
	c = spinC->value();
	d = spinD->value();
	e = spinE->value();

	if (fileFull.isEmpty())
	{
		std::string infoStr("请先选择图片及设置正确参数");
		QString infoText = QString::fromLocal8Bit(infoStr.data());
		QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
	}
	else if(srcI.empty())
	{
		std::string infoStr("请先进行灰度变换");
		QString infoText = QString::fromLocal8Bit(infoStr.data());
		QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
	}
	else
	{
		if (selectBox->currentIndex() == 0)
		{
			if ((a == b && b == c && c == d) || (a > b))
			{
				std::string infoStr("请设置正确参数");
				QString infoText = QString::fromLocal8Bit(infoStr.data());
				QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
			}
			else
			{
				dstI = PieGrayTo(srcI, a, b, c, d);
				imshow("分段线性变换", dstI);
				srcI = readFile(fileFull.toStdString());
			}
		}
		else if (selectBox->currentIndex() == 1)
		{
			if (e == 0)
			{
				std::string infoStr("请设置正确参数");
				QString infoText = QString::fromLocal8Bit(infoStr.data());
				QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
			}
			else
			{
				dstI = LogGrayTo(srcI, e);
				imshow("对数灰度变换", dstI);
				srcI = readFile(fileFull.toStdString());
			}
		}
	}
}

void GrayST::saveImageSlot()
{
	if (dstI.empty())
	{
		std::string infoStr("请先进行转换");
		QString infoText = QString::fromLocal8Bit(infoStr.data());
		QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
	}
	else
	{
		if (selectBox->currentIndex() == 0)
		{
			std::string infoStr(savePieMat(dstI, filePath.toStdString(), fileSuffix.toStdString(), a, b, c, d));
			QString infoText = QString::fromLocal8Bit(infoStr.data());
			QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
		}
		if (selectBox->currentIndex() == 1)
		{
			std::string infoStr(saveLogMat(dstI, filePath.toStdString(), fileSuffix.toStdString(),e));
			QString infoText = QString::fromLocal8Bit(infoStr.data());
			QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
		}
	}
}

void GrayST::setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor)
{
	int sliderHeight = 8;
	int sliderRadius = 4;
	int handleWidth = 13;
	int handleRadius = 6;
	int handleOffset = 3;

	QStringList qss;
	qss.append(QString("QSlider::groove:horizontal,QSlider::add-page:horizontal{height:%2px;border-radius:%3px;background:%1;}").arg(normalColor).arg(sliderHeight).arg(sliderRadius));
	qss.append(QString("QSlider::sub-page:horizontal{height:%2px;border-radius:%3px;background:%1;}").arg(grooveColor).arg(sliderHeight).arg(sliderRadius));
	qss.append(QString("QSlider::handle:horizontal{width:%2px;margin-top:-%3px;margin-bottom:-%3px;border-radius:%4px;"
		"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #FFFFFF,stop:0.8 %1);}")
		.arg(handleColor).arg(handleWidth).arg(handleOffset).arg(handleRadius));
	slider->setStyleSheet(qss.join(""));
}

QPixmap GrayST::matToQP(cv::Mat showM)
{
	QImage showI((unsigned char*)(showM.data), showM.cols,
		showM.rows, QImage::Format_Indexed8);
	QPixmap showQ;
	showQ = QPixmap::fromImage(showI);
	return showQ;
}

void GrayST::showWid(cv::Mat showM)
{
}