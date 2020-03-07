#include "UrlWindow.h"
#include "AudioDownloader.h"
#include <QProcess>
#include <qfile.h>
#include <QDir>
#include <qtextstream.h>
#include <qdebug.h>
#include <QRegExp>

UrlWindow::UrlWindow(QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);
	ui.pushButton->setEnabled(false);
	ui.progressBar->setMaximum(0);
	ui.progressBar->setMinimum(0);
	ui.progressBar->hide();
	downloadUrlRegexp = QRegExp("^(https:\\/\\/)?(www\\.)?youtube\\.com\\/watch\\?v=.+");
	cachedUrl = "";
}

UrlWindow::~UrlWindow(){

}


void UrlWindow::on_lineEdit_textChanged(const QString& text) {
	if (downloadUrlRegexp.exactMatch(text)) {
		ui.pushButton->setEnabled(true);
		cachedUrl = text;
	}
	else
		ui.pushButton->setDisabled(true);
}

void UrlWindow::on_pushButton_clicked() {
	AudioDownloader* download = new AudioDownloader(this, cachedUrl, ui.textEdit, ui.pushButton, ui.progressBar);
}

void UrlWindow::on_lineEdit_returnPressed() {
	if (ui.pushButton->isEnabled()) {
		ui.pushButton->clicked();
	}
}