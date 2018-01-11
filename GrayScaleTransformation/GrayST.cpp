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

	this->setWindowOpacity(0.9); //��������͸���ȣ�0-1 ��ȫ͸������͸��  
}
GrayST::~GrayST()
{

}

void GrayST::createAction()
{
	//�������ļ�����  �����źźͲ� 
	fileOpenAction = new QAction(QIcon(":/GrayST/Resources/1.png"), tr("Select Image"), this);
	connect(fileOpenAction, SIGNAL(triggered()), this, SLOT(fileOpenActionSlot()));
	//�����򿪻Ҷ�ͼ����  ����
	openGrayscaleAction = new QAction(QIcon(":/GrayST/Resources/2.png"), tr("Open GrayScale"), this);
	connect(openGrayscaleAction, SIGNAL(triggered()), this, SLOT(openGrayscaleSlot()));
	//�����Ҷ�ת������   ����
	traslateAction = new QAction(QIcon(":/GrayST/Resources/3.png"), tr("Traslate"), this);
	connect(traslateAction, SIGNAL(triggered()), this, SLOT(traslateSlot()));
	//��������ͼƬ����  ����
	saveImageAction = new QAction(QIcon(":/GrayST/Resources/4.png"), tr("Save"), this);
	connect(saveImageAction, SIGNAL(triggered()), this, SLOT(saveImageSlot()));
	//�����򿪰����ĵ�����  ����
	helpOpenAction = new QAction(QIcon(":/GrayST/Resources/5.png"), tr("Open Help"), this);
	connect(helpOpenAction, SIGNAL(triggered()), this, SLOT(helpOpenActionSlot()));
}


void GrayST::createToolBar()
{
	//��ʼ���ļ�����
	fileTool = addToolBar("File");
	fileTool->addAction(fileOpenAction);
	fileTool->setStatusTip("Select Image");
	//��ʼ���򿪻Ҷ�ͼ����
	grayscaleTool = addToolBar("Open GrayScale");
	grayscaleTool->addAction(openGrayscaleAction);
	grayscaleTool->setStatusTip("Open GrayScale");
	//��ʼ��ת������
	traslateTool = addToolBar("Traslate");
	traslateTool->addAction(traslateAction);
	//traslateTool->setStatusTip("Traslate and Open");
	//��ʼ�����湤��
	saveImageTool = addToolBar("save");
	saveImageTool->addAction(saveImageAction);

	//������������
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

	spinA->setRange(0, 255); //�������ַ�Χ
	spinB->setRange(0, 255);
	spinC->setRange(0, 255);
	spinD->setRange(0, 255);
	sliderA->setRange(0, 255);
	sliderB->setRange(0, 255);
	sliderC->setRange(0, 255);
	sliderD->setRange(0, 255);

	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	//����QSpinBox��QSlider
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

	gLayout->setHorizontalSpacing(10);// ����ˮƽ���
	gLayout->setVerticalSpacing(5);  // ���ô�ֱ���
	gLayout->setContentsMargins(10, 10, 10, 10);// ��������
	widget->setLayout(gLayout);
}


void  GrayST::fileOpenActionSlot()
{
	//�����ļ��Ի�����  
	QFileDialog *fileDialog = new QFileDialog(this);
	//�����ļ��Ի������  
	fileDialog->setWindowTitle(tr("Open Image"));
	//����Ĭ���ļ�·��  
	fileDialog->setDirectory(".");
	//�����ļ�������  
	fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
	//����ֻ��ѡ��һ���ļ�QFileDialog::ExistingFiles  
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	//������ͼģʽ  
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
	std::string helpStr("ͨ������A,B,C,D��ֵ�����Զ���һ�Ҷ����������չ��ѹ����\n���һ��ͼ��ƫ������ʹб��>1�����ơ�\n���һ��ͼ��ƫ������ʹб��<1������\n���ߣ�Flyuz  QQ��522893161");
	QString helpText = QString::fromLocal8Bit(helpStr.data());
	QMessageBox::information(this, "Help", helpText, QMessageBox::Ok);//�¸��汾���ͼ��~
}

void GrayST::openGrayscaleSlot()
{
	if (fileFull.isEmpty())
	{
		std::string infoStr("����ѡ��ͼƬ");
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
		std::string infoStr("����ѡ��ͼƬ��������ȷ����");
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
		std::string infoStr("���Ƚ���ת��");
		QString infoText = QString::fromLocal8Bit(infoStr.data());
		QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
	}
	else
	{
		if (saveMat(dstI, filePath.toStdString(), fileSuffix.toStdString(), a, b, c, d))
		{
			std::string infoStr("����ɹ�");
			QString infoText = QString::fromLocal8Bit(infoStr.data());
			QMessageBox::information(this, "!", infoText, QMessageBox::Ok);
		}
	}
}