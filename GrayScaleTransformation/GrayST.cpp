#include "GrayST.h"

/**
By NWAFU Flyuz
http://blog.csdn.net/ZHangFFYY/
2018/1/10
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
	fileOpenAction = new QAction(QIcon(":/GrayST/Resources/1.png"), tr("Select Image"), this);
	connect(fileOpenAction, SIGNAL(triggered()), this, SLOT(fileOpenActionSlot()));
	//创建打开灰度图动作  关联
	openGrayscaleAction = new QAction(QIcon(":/GrayST/Resources/2.png"), tr("Open GrayScale"), this);
	connect(openGrayscaleAction, SIGNAL(triggered()), this, SLOT(openGrayscaleSlot()));
	//创建灰度转换动作   关联
	traslateAction = new QAction(QIcon(":/GrayST/Resources/3.png"), tr("Traslate"), this);
	connect(traslateAction, SIGNAL(triggered()), this, SLOT(traslateSlot()));
	//创建保存图片动作  关联
	saveImageAction = new QAction(QIcon(":/GrayST/Resources/4.png"), tr("Save"), this);
	connect(saveImageAction, SIGNAL(triggered()), this, SLOT(saveImageSlot()));
	//创建打开帮助文档动作  关联
	helpOpenAction = new QAction(QIcon(":/GrayST/Resources/5.png"), tr("Open Help"), this);
	connect(helpOpenAction, SIGNAL(triggered()), this, SLOT(helpOpenActionSlot()));
}


void GrayST::createToolBar()
{
	//初始化文件工具
	fileTool = addToolBar("File");
	fileTool->addAction(fileOpenAction);
	fileTool->setStatusTip("Select Image");
	//初始化打开灰度图工具
	grayscaleTool = addToolBar("Open GrayScale");
	grayscaleTool->addAction(openGrayscaleAction);
	grayscaleTool->setStatusTip("Open GrayScale");
	//初始化转换工具
	traslateTool = addToolBar("Traslate");
	traslateTool->addAction(traslateAction);
	//traslateTool->setStatusTip("Traslate and Open");
	//初始化保存工具
	saveImageTool = addToolBar("save");
	saveImageTool->addAction(saveImageAction);

	//创建帮助工具
	helpTool = addToolBar("Help");
	helpTool->addAction(helpOpenAction);
	//helpTool->setStatusTip("Open Help");
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

	spinA->setRange(0, 255); //设置数字范围
	spinB->setRange(0, 255);
	spinC->setRange(0, 255);
	spinD->setRange(0, 255);
	sliderA->setRange(0, 255);
	sliderB->setRange(0, 255);
	sliderC->setRange(0, 255);
	sliderD->setRange(0, 255);

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

	labelA = new QLabel("Parameter A:  ");
	labelB = new QLabel("Parameter B:  ");
	labelC = new QLabel("Parameter C:  ");
	labelD = new QLabel("Parameter D:  ");

	QWidget *widget = new QWidget(this);
	this->setCentralWidget(widget);
	QGridLayout *gLayout = new QGridLayout();
	gLayout->addWidget(labelA, 0, 0, 1, 1, Qt::AlignRight);
	gLayout->addWidget(spinA, 0, 1, 1, 1);
	gLayout->addWidget(sliderA, 0, 2, 1, 2);

	gLayout->addWidget(labelB, 1, 0, 1, 1, Qt::AlignRight);
	gLayout->addWidget(spinB, 1, 1, 1, 1);
	gLayout->addWidget(sliderB, 1, 2, 1, 2);

	gLayout->addWidget(labelC, 2, 0, 1, 1, Qt::AlignRight);
	gLayout->addWidget(spinC, 2, 1, 1, 1);
	gLayout->addWidget(sliderC, 2, 2, 1, 2);

	gLayout->addWidget(labelD, 3, 0, 1, 1, Qt::AlignRight);
	gLayout->addWidget(spinD, 3, 1, 1, 1);
	gLayout->addWidget(sliderD, 3, 2, 1, 2);

	gLayout->setHorizontalSpacing(10);// 设置水平间距
	gLayout->setVerticalSpacing(5);  // 设置垂直间距
	gLayout->setContentsMargins(10, 10, 10, 10);// 设置外间距
	widget->setLayout(gLayout);
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
	std::string helpStr("通过设置A,B,C,D的值，可以对任一灰度区间进行扩展或压缩。\n如果一幅图像偏暗，可使斜率>1来改善。\n如果一幅图像偏亮，可使斜率<1来改善\n作者：Flyuz  QQ：522893161");
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
	}
}

void GrayST::traslateSlot()
{
	a = spinA->value();
	b = spinB->value();
	c = spinC->value();
	d = spinD->value();
	if (fileFull.isEmpty() || (a == b && b == c && c == d) || (a > b))
	{
		std::string infoStr("请先选择图片及设置正确参数");
		QString infoText = QString::fromLocal8Bit(infoStr.data());
		QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
	}
	else
	{
		dstI = GrayTo(srcI, a, b, c, d);
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
		if (saveMat(dstI, filePath.toStdString(), fileSuffix.toStdString(), a, b, c, d))
		{
			std::string infoStr("保存成功");
			QString infoText = QString::fromLocal8Bit(infoStr.data());
			QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
		}
	}
}