#ifndef DOWNLOAD_H
#define DOWNLOAD_H
#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QTextCodec>
#include <QEventLoop>

class download : public QObject
{
    Q_OBJECT
public:
    explicit download(QObject *parent = 0);
    QString down(const QUrl &url);

    bool isFinish=false;

public slots:

private slots:

private:
    QNetworkAccessManager *manager;
};

#endif // DOWNLOAD_H
