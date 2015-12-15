#include "download.h"

download::download(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();
}

QString download::down(const QUrl &url)
{
    QEventLoop loop;
    QNetworkReply *reply = manager->get(QNetworkRequest(url));
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    auto bbf = codec->toUnicode(reply->readAll().data()).toUtf8();
    reply->deleteLater();
    return QString(bbf);
}
