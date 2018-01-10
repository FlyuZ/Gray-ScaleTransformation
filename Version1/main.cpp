#include "Version1.h"
#include <QtWidgets/QApplication>
//#include <QProcess>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QIcon icon;
	icon.addFile(QStringLiteral(":/Version1/Resources/Ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
	
	Version1 window;
	window.setWindowTitle(QObject::tr("Gray-Scale transformation"));
	window.setWindowIcon(icon);
	window.show();
	window.resize(480, 320);

	return app.exec();
}
