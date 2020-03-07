#include "UrlWindow.h"
#include "AudioDownloader.h"
#include <QProcess>
#include <qfile.h>
#include <QDir>
#include <qtextstream.h>
#include <qdebug.h>

UrlWindow::UrlWindow(QWidget *parent) : QMainWindow(parent){
	ui.setupUi(this);
	//ui.graphicsView->hide();
	ui.pushButton->setEnabled(false);
}

UrlWindow::~UrlWindow(){

}


void UrlWindow::on_lineEdit_textChanged(const QString& text) {
	//QProcess* thumbnailDownload = new QProcess(this);
	AudioDownloader* download = new AudioDownloader(this, text, ui.textEdit);
	

	
	
	
	//thumbnailDownload->setReadChannel(QProcess::StandardOutput);
	//connect(thumbnailDownload, SIGNAL(readyReadStandardOutput()), this, SLOT(on_thumbnailDownload_readyReadStandartOutput()));
	//thumbnailDownloadArgumentsList = thumbnailDownloadArgumentsList << text;
	//thumbnailDownload->start("C:/Windows/system32/cmd.exe", thumbnailDownloadArgumentsList);
	//thumbnailDownload->start("cmd", QStringList() << "/C" << "> C:/UNIV" << "notepad");
	////thumbnailDownload->start("cmd");
	//thumbnailDownload->waitForFinished();

	//qDebug() << thumbnailDownload->exitCode();

	//command = "youtube-dl";
	//defaultResultName = "%(title)s.%(ext)s";

	//saveLocation = QDir::currentPath() + "/" + defaultResultName;
	//QFile saveLocationFile("Resources/settings.cyd");
	//QTextStream saveLocFileStream(&saveLocationFile);

	//qDebug() << saveLocation;

	//if (saveLocationFile.open(QFile::ExistingOnly | QFile::ReadOnly)) {
	//	saveLocation = saveLocFileStream.readLine();
	//}
	//else {
	//	if (saveLocationFile.open(QFile::WriteOnly)) {
	//		qDebug() << saveLocation;

	//		saveLocFileStream << saveLocation;

	//		qDebug() << saveLocation;
	//	}
	//}


	//argumentsList << "--extract-audio"
	//	<< "--audio-format"
	//	<< "mp3"
	//	<< "-o"
	//	<< saveLocation
	//	<< text;
	////thumbnailDownload->start(command, argumentsList);
	//thumbnailDownload->start("C:/windows/system32/cmd.exe", QStringList() << "/C" << "> C:/out" << argumentsList);
	//thumbnailDownload->waitForFinished();
	//qDebug() << thumbnailDownload->readAll();
	//try to download thumbnail
	//if success - show it and activate download button
	//if not success - don't show empty graphics view, deactivate download button
}

//void UrlWindow::on_thumbnailDownload_readyReadStandartOutput(){
//	//QString temp = QString::fromStdString(thumbnailDownload->readAllStandardOutput().toStdString());
//	
//	//qDebug() << thumbnailDownload->readAll();
//	//QByteArray temp = thumbnailDownload->readAllStandardOutput();
//	//ui.textEdit->append(temp);
//}
