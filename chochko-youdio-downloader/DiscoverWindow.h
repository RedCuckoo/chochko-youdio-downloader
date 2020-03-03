#ifndef DISCOVERWINDOW_H
#define DISCOVERWINDOW_H

#include <QMainWindow>
#include "ui_DiscoverWindow.h"

class DiscoverWindow : public QMainWindow{
	Q_OBJECT

public:
	DiscoverWindow(QWidget *parent = Q_NULLPTR);
	~DiscoverWindow();

	QString homePage;

private:
	Ui::DiscoverWindow ui;
	//TODO: debug and enable this for nice graphics
	//void on_webEngineView_urlChanged(const QUrl& url);

private slots:
	void on_actionBack_triggered();
	void on_actionForward_triggered();
	void on_actionRefresh_triggered();
	void on_actionHomepage_triggered();

};

#endif //DISCOVERWINDOW_H