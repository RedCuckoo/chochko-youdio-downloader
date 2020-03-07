#ifndef URLWINDOW_H
#define URLWINDOW_H

#include <QMainWindow>
#include "ui_UrlWindow.h"
#include <QProcess>
#include <QRegExp>

class UrlWindow : public QMainWindow{
	Q_OBJECT

public:
	UrlWindow(QWidget *parent = Q_NULLPTR);
	~UrlWindow();

private:
	Ui::UrlWindow ui;

	QString command;
	QString saveLocation;
	QString defaultResultName;
	QStringList argumentsList;
	QRegExp downloadUrlRegexp;

	QString cachedUrl;
private slots:
	void on_lineEdit_textChanged(const QString& text);
	void on_pushButton_clicked();
};                     


#endif //URLWINDOW_H