#include "DiscoverWindow.h"
#include <QWebEnginePage>
#include <QWebEngineHistory>

DiscoverWindow::DiscoverWindow(QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);
	homePage = "https://youtube.com";
	ui.webEngineView->setUrl(homePage);
}

DiscoverWindow::~DiscoverWindow(){

}


//void DiscoverWindow::on_webEngineView_urlChanged(const QUrl& url) {
//	QWebEngineHistory* history = ui.webEngineView->history();
//	if (history->canGoBack()) {
//		ui.actionBack->setCheckable(true);
//	}
//	else {
//		ui.actionBack->setCheckable(false);
//	}	
//	
//	if (history->canGoForward()) {
//		ui.actionForward->setCheckable(true);
//	}
//	else {
//		ui.actionForward->setCheckable(false);
//	}
//
//	qDebug() << history->canGoBack() << history->canGoForward();
//}

void DiscoverWindow::on_actionBack_triggered() {
	ui.webEngineView->triggerPageAction(QWebEnginePage::Back);
}

void DiscoverWindow::on_actionForward_triggered() {
	ui.webEngineView->triggerPageAction(QWebEnginePage::Forward);
}

void DiscoverWindow::on_actionRefresh_triggered() {
	ui.webEngineView->triggerPageAction(QWebEnginePage::Reload);
}

void DiscoverWindow::on_actionHomepage_triggered() {
	ui.webEngineView->setUrl(homePage);
}