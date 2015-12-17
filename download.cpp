#include "download.h"

download::download(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();
    goodsTimer = new QTimer(this);
    connect( goodsTimer, SIGNAL(timeout()), this, SLOT(check()) );
     connect( this, SIGNAL(sendCheckGoodsFinish()), this, SLOT(stopGoodsCheck()) );
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
void download::setUrl(QUrl &url){
    this->url = url;
}

//检查循环
void download::check(){
    auto cc = down(url);
    if(isGetGoods){
        emit sendCheckGoodsFinish();
    }
}
//停止循环
void download::stopGoodsCheck(){
    goodsTimer->stop();
    QMessageBox::information(NULL,"","结束");
}
void download::start(){
      goodsTimer->start(200);
}
void download::stop(){
    goodsTimer->stop();
}
