#include "QtCoin3D_Robot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtCoin3D_Robot w;
	w.show();
	return a.exec();
}
