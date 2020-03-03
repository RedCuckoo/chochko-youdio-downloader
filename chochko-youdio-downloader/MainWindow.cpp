#include "MainWindow.h"
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	command = "youtube-dl";
	defaultResultName = "(title)s.%(ext)s";
	saveLocation = QDir::currentPath() + "/" + defaultResultName;
	homePage = "https://youtube.com";

	QFile saveLocationFile("Resources/settings.cyd");
	QTextStream saveLocFileStream(&saveLocationFile);
	if (saveLocationFile.open(QFile::ExistingOnly | QFile::ReadOnly)) {
		saveLocation = saveLocFileStream.readLine();
	}
	else {
		if (saveLocationFile.open(QFile::WriteOnly)) {
			saveLocFileStream >> saveLocation;
		}
	}
	
	argumentsList << "--extract-audio"
		<< "--audio-format"
		<< "mp3"
		<< "-o"
		<< saveLocation
		<< ""; //[5] - url

	ui.webEngineView->setUrl(homePage);
}
