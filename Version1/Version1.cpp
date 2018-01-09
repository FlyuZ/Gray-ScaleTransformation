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
	//�������ļ�����  
	fileOpenAction = new QAction(tr("Open Image"), this); 
	//�������ļ��������źźͲ�  
	connect(fileOpenAction, SIGNAL(triggered()), this, SLOT(fileOpenActionSlot()));
	//�����򿪰����ĵ�����
	helpOpenAction = new QAction(tr("Open Help"), this);
	//���������ĵ����źźͲ�
	connect(helpOpenAction, SIGNAL(triggered()), this, SLOT(helpOpenActionSlot()));
}

void  Version1::createMenu()
{
	fileMenu = this->menuBar()->addMenu(tr("&File")); //�����ļ��˵�
	helpMenu = this->menuBar()->addMenu(tr("Help")); //���������˵�
	fileMenu->addAction(fileOpenAction);
	helpMenu->addAction(helpOpenAction);
}
void Version1::createToolBar()
{
	fileTool = addToolBar(tr("&File")); //�����ļ�����
	fileTool->addAction(fileOpenAction);
	helpTool = addToolBar(tr("Help")); //������������
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

	gLayout->setHorizontalSpacing(10);// ����ˮƽ���
	gLayout->setVerticalSpacing(10);  // ���ô�ֱ���
	gLayout->setContentsMargins(10, 10, 10, 10);// ��������
	this->setLayout(gLayout);
}


void  Version1::fileOpenActionSlot()
{
	//�����ļ��Ի�����  
	QFileDialog *fileDialog = new QFileDialog(this);
	//�����ļ��Ի������  
	fileDialog->setWindowTitle(tr("Open Image"));
	//����Ĭ���ļ�·��  
	fileDialog->setDirectory(".");
	//�����ļ�������  
	fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
	//���ÿ���ѡ�����ļ�,Ĭ��Ϊֻ��ѡ��һ���ļ�QFileDialog::ExistingFiles  
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	//������ͼģʽ  
	fileDialog->setViewMode(QFileDialog::Detail);
	//��ӡ����ѡ����ļ���·��  
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
	std::string helpStr("˵���ĵ�");
	QString helpText = QString::fromLocal8Bit(helpStr.data());
	QMessageBox::information(this, "Help", helpText, QMessageBox::Ok);//�¸��汾���ͼ��~
}