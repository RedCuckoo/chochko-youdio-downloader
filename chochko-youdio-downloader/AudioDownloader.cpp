#include "AudioDownloader.h"
#include <QDir>
#include <QTextStream>
#include <QTextEdit>
#include <QProcess>
#include <QPushButton>
#include <QProgressBar>

AudioDownloader::AudioDownloader(QObject *parent, QString url, QTextEdit* output, QPushButton* button, QProgressBar* progressBar) : QObject(parent){
	command = "youtube-dl";
	defaultResultName = "%(title)s.%(ext)s";
	saveLocation = QDir::currentPath() + "/" + defaultResultName;

	QFile saveLocationFile("Resources/settings.cyd");
	QTextStream saveLocFileStream(&saveLocationFile);
	if (saveLocationFile.open(QFile::ExistingOnly | QFile::ReadOnly)) {
		saveLocation = saveLocFileStream.readLine();
	}
	else {
		if (saveLocationFile.open(QFile::WriteOnly)) {
			saveLocFileStream << saveLocation;
		}
	}

	argumentsList << "-x"
		<< "--audio-format"
		<< "mp3"
		<< "--prefer-avconv"
		<< "-o"
		<< saveLocation
		<< url;

	this->output = output;
	this->button = button;
	this->progressBar = progressBar;

	QProcess* downloadProcess = new QProcess(parent);
	connect(downloadProcess, SIGNAL(started()), this, SLOT(on_downloadProcess_started()));
	connect(downloadProcess, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(on_downloadProcess_errorOccurred(QProcess::ProcessError)));
	connect(downloadProcess, SIGNAL(finished(int, QProcess::ExitStatus)) , this, SLOT(on_downloadProcess_finished(int, QProcess::ExitStatus)));
	
	downloadProcess->start(command, argumentsList);
}

AudioDownloader::~AudioDownloader(){

}

void AudioDownloader::on_downloadProcess_started() {
	output->append("Download started");
	button->setDisabled(true);

	if(progressBar)
		progressBar->show();
}

void AudioDownloader::on_downloadProcess_errorOccurred(QProcess::ProcessError error) {
	QFile logFile(QDir::currentPath() + "/logs/last_log.cyd");
	QTextStream logFileStream(&logFile);
	logFile.open(QFile::WriteOnly);
	
	logFileStream << command;
	for (QString i : argumentsList) {
		logFileStream << i;
	}
	logFileStream << '\n';

	QString log;

	switch (error) {
	case QProcess::FailedToStart:
		log = "PROCESS FAILED TO START";
		break;
	case QProcess::Crashed:
		log = "PROCESS CRASHED";
		break;
	case QProcess::Timedout:
		log = "PROCESS TIME IS OUT";
		break;
	case QProcess::WriteError:
		log = "PROCESS WRITE FAILED";
		break;
	case QProcess::ReadError:
		log = "PROCESS READ FAILED";
		break;
	case QProcess::UnknownError:
		log = "PROCESS FAILED WITH UNKNOWN ERROR";
		break;
	}

	output->append(log);

	logFileStream << log;

	logFile.close();
}

void AudioDownloader::on_downloadProcess_finished(int exitCode, QProcess::ExitStatus exitStatus) {
	switch(exitStatus){
	case QProcess::NormalExit:
		output->append("Download finished with success\n");
		break;
	case QProcess::CrashExit:
		output->append("ERROR OCCURED\n");
		break;
	}

	button->setEnabled(true);
	
	if(progressBar)
		progressBar->hide();
}
