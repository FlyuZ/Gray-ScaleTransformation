#include "GraySTui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QIcon icon;
	icon.addFile(QStringLiteral(":/GrayST/Resources/Ico.ico"), QSize(), QIcon::Normal, QIcon::Off);

	GrayST window;
	window.setWindowTitle(QObject::tr("Gray-Scale-Transformation v1.9.3"));
	window.setWindowIcon(icon);
	
	window.show();
	window.resize(480, 320);

	return a.exec();
}
