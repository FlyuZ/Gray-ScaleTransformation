#include "Version1.h"

Version1::Version1(QWidget *parent)
	: QMainWindow(parent)
{
	createAction();
	createMenu();
	createToolBar();
	initWindow();
	ui.setupUi(this);
}

void Version1::createAction()
{
	//创建打开文件动作  
	fileOpenAction = new QAction(tr("Open Image"), this); 
	//关联打开文件动作的信号和槽  
	connect(fileOpenAction, SIGNAL(triggered()), this, SLOT(fileOpenActionSlot()));
	//创建打开帮助文档动作
	helpOpenAction = new QAction(tr("Open Help"), this);
	//关联帮助文档的信号和槽
	connect(helpOpenAction, SIGNAL(triggered()), this, SLOT(helpOpenActionSlot()));
}

void  Version1::createMenu()
{
	fileMenu = this->menuBar()->addMenu(tr("&File")); //创建文件菜单
	helpMenu = this->menuBar()->addMenu(tr("Help")); //创建帮助菜单
	fileMenu->addAction(fileOpenAction);
	helpMenu->addAction(helpOpenAction);
}
void Version1::createToolBar()
{
	fileTool = addToolBar(tr("&File")); //创建文件工具
	fileTool->addAction(fileOpenAction);
	helpTool = addToolBar(tr("Help")); //创建帮助工具
	helpTool->addAction(helpOpenAction);
}

void  Version1::initWindow()
{
	spinA = new QSpinBox(this);
	sliderA = new QSlider(this);
	spinB = new QSpinBox(this);
	sliderB = new QSlider(this);
	spinC = new QSpinBox(this);
	sliderC = new QSlider(this);
	spinD = new QSpinBox(this);
	sliderD = new QSlider(this);

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

	QGridLayout *gLayout = new QGridLayout();

	gLayout->addWidget(spinA, 0, 0, 1, 1);
	gLayout->addWidget(sliderA, 0, 1, 1, 2);

	gLayout->addWidget(spinB, 1, 0, 1, 1);
	gLayout->addWidget(sliderB, 1, 1, 1, 2);

	gLayout->addWidget(spinC, 2, 0, 1, 1);
	gLayout->addWidget(sliderC, 2, 1, 1, 2);

	gLayout->addWidget(spinD, 3, 0, 1, 1);
	gLayout->addWidget(sliderD, 3, 1, 1, 2);

	gLayout->setHorizontalSpacing(10);// 设置水平间距
	gLayout->setVerticalSpacing(10);  // 设置垂直间距
	gLayout->setContentsMargins(10, 10, 10, 10);// 设置外间距
	this->setLayout(gLayout);
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
	//设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles  
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	//设置视图模式  
	fileDialog->setViewMode(QFileDialog::Detail);
	//打印所有选择的文件的路径  
	QStringList fileNames;
	if (fileDialog->exec())
	{
		fileNames = fileDialog->selectedFiles();
	}
	for (auto tmp : fileNames)
		qDebug() << tmp << endl;
}

void Version1::helpOpenActionSlot()
{
	std::string helpStr("说明文档");
	QString helpText = QString::fromLocal8Bit(helpStr.data());
	QMessageBox::information(this, "Help", helpText, QMessageBox::Ok);//下个版本添加图标~
}