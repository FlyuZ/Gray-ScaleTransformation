#include "Version1.h"
#include "Translation.h"

Version1::Version1(QWidget *parent)
	: QMainWindow(parent)
{
	createAction();
	createMenu();
	createToolBar();
	initWindow();
	//ui.setupUi(this);
}

void Version1::createAction()
{
	//创建打开文件动作  
	fileOpenAction = new QAction(tr("Select Image"), this); 
	//关联打开文件动作的信号和槽  
	connect(fileOpenAction, SIGNAL(triggered()), this, SLOT(fileOpenActionSlot()));
	//创建打开帮助文档动作
	helpOpenAction = new QAction(tr("Open Help"), this);
	//关联帮助文档的信号和槽
	connect(helpOpenAction, SIGNAL(triggered()), this, SLOT(helpOpenActionSlot()));
	//
	openGrayscaleAction = new QAction(tr("Open GrayScale"), this);
	connect(openGrayscaleAction, SIGNAL(triggered()), this, SLOT(openGrayscaleSlot()));
	//
	traslateAction = new QAction(tr("Traslate"), this);
	connect(traslateAction, SIGNAL(triggered()), this, SLOT(traslateSlot()));
}

void  Version1::createMenu()
{
	fileMenu = this->menuBar()->addMenu(tr("File")); //创建文件菜单
	helpMenu = this->menuBar()->addMenu(tr("Help")); //创建帮助菜单
	fileMenu->addAction(fileOpenAction);
	helpMenu->addAction(helpOpenAction);
}
void Version1::createToolBar()
{
	fileTool = addToolBar(tr("File")); //创建文件工具
	fileTool->addAction(fileOpenAction);
	grayscaleTool = addToolBar(tr("Open GrayScale"));//创建打开灰度图工具
	grayscaleTool->addAction(openGrayscaleAction);
	traslateTool = addToolBar(tr("Traslate"));//创建转换工具
	traslateTool->addAction(traslateAction);
	helpTool = addToolBar(tr("Help")); //创建帮助工具
	helpTool->addAction(helpOpenAction);
}

void  Version1::initWindow()
{
	spinA = new QSpinBox(this);
	sliderA = new QSlider(Qt::Horizontal,this);
	spinB = new QSpinBox(this);
	sliderB = new QSlider(Qt::Horizontal,this);
	spinC = new QSpinBox(this);
	sliderC = new QSlider(Qt::Horizontal,this);
	spinD = new QSpinBox(this);
	sliderD = new QSlider(Qt::Horizontal,this);

	spinA->setRange(0, 255);
	spinB->setRange(0, 255);
	spinC->setRange(0, 255);
	spinD->setRange(0, 255);
	sliderA->setRange(0, 255);
	sliderB->setRange(0, 255);
	sliderC->setRange(0, 255);
	sliderD->setRange(0, 255);

	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
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

	labelA = new QLabel("A");
	labelB = new QLabel("B");
	labelC = new QLabel("C");
	labelD = new QLabel("D");

	QWidget *widget = new QWidget(this);
	this->setCentralWidget(widget);
	QGridLayout *gLayout = new QGridLayout();
	gLayout->addWidget(labelA, 0, 0, 1, 1);
	gLayout->addWidget(spinA, 0, 1, 1, 1);
	gLayout->addWidget(sliderA, 0, 2, 1, 2);

	gLayout->addWidget(labelB, 1, 0, 1, 1);
	gLayout->addWidget(spinB, 1, 1, 1, 1);
	gLayout->addWidget(sliderB, 1, 2, 1, 2);

	gLayout->addWidget(labelC, 2, 0, 1, 1);
	gLayout->addWidget(spinC, 2, 1, 1, 1);
	gLayout->addWidget(sliderC, 2, 2, 1, 2);

	gLayout->addWidget(labelD, 3, 0, 1, 1);
	gLayout->addWidget(spinD, 3, 1, 1, 1);
	gLayout->addWidget(sliderD, 3, 2, 1, 2);

	gLayout->setHorizontalSpacing(10);// 设置水平间距
	gLayout->setVerticalSpacing(5);  // 设置垂直间距
	gLayout->setContentsMargins(10, 10, 10, 10);// 设置外间距
	widget->setLayout(gLayout);
}


void  Version1::fileOpenActionSlot()
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
	//打印所有选择的文件的路径  

	if (fileDialog->exec())
	{
		fileName = fileDialog->selectedFiles()[0];
	}
}

void Version1::helpOpenActionSlot()
{
	std::string helpStr("说明文档");
	QString helpText = QString::fromLocal8Bit(helpStr.data());
	QMessageBox::information(this, "Help", helpText, QMessageBox::Ok);//下个版本添加图标~
}

void Version1::openGrayscaleSlot()
{
	srcI = readFile(fileName.toStdString());
}

void Version1::traslateSlot()
{

}