 #include "UrlWindow.h"

UrlWindow::UrlWindow(QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);
}

UrlWindow::~UrlWindow(){

}

void UrlWindow::on_lineEdit_textChanged(const QString& text) {
	//try to download thumbnail
	//if success - show it and activate download button
	//if not success - don't show empty graphics view, deactivate download button
}
