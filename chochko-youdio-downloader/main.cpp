#include "MainWindow.h"
#include "DiscoverWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DiscoverWindow w;
	w.show();
	return a.exec();
}
