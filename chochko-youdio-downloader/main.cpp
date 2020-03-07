#include "UrlWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UrlWindow w;
	w.show();
	return a.exec();
}
