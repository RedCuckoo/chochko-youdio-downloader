#ifndef URLWINDOW_H
#define URLWINDOW_H

#include <QMainWindow>
#include "ui_UrlWindow.h"
#include <QProcess>

class UrlWindow : public QMainWindow{
	Q_OBJECT

public:
	UrlWindow(QWidget *parent = Q_NULLPTR);
	~UrlWindow();

private:
	Ui::UrlWindow ui;
	//QProcess* thumbnailDownload;
	QString command;
	QString saveLocation;
	QString defaultResultName;
	QStringList argumentsList;
private slots:
	void on_lineEdit_textChanged(const QString& text);
	//void on_thumbnailDownload_readyReadStandartOutput();
};                     


#endif //URLWINDOW_H