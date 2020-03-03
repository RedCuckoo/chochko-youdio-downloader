#ifndef URLWINDOW_H
#define URLWINDOW_H

#include <QMainWindow>
#include "ui_UrlWindow.h"

class UrlWindow : public QMainWindow{
	Q_OBJECT

public:
	UrlWindow(QWidget *parent = Q_NULLPTR);
	~UrlWindow();

private:
	Ui::UrlWindow ui;

private slots:
	void on_lineEdit_textChanged(const QString& text);
};


#endif //URLWINDOW_H