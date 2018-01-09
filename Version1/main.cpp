#include "Version1.h"
#include <QtWidgets/QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Version1 window;
	window.setWindowTitle(QObject::tr("Gray-Scale transformation"));

	window.show();

	return app.exec();
}