#ifndef AUDIODOWNLOADER_H
#define AUDIODOWNLOADER_H

#include <QObject>
#include <QTextEdit>
#include <QProcess>

class AudioDownloader : public QObject{
	Q_OBJECT

public:
	AudioDownloader(QObject *parent, QString url, QTextEdit* output);
	~AudioDownloader();
private:
	QString command;
	QString saveLocation;
	QString defaultResultName;
	QStringList argumentsList;
	QTextEdit* output;
private slots:
	void on_downloadProcess_started();
	void on_downloadProcess_finished(int exitCode, QProcess::ExitStatus exitStatus);
	void on_downloadProcess_errorOccurred(QProcess::ProcessError);
};

#endif //AUDIODOWNLOADER_H