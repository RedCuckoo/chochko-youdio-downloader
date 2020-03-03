#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QProcess>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	QString command;
	QString saveLocation;
	QString defaultResultName;
	QStringList argumentsList;
	QString homePage;
private:
	Ui::MainWindowClass ui;
};
