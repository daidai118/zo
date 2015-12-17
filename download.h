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
#include <QTimer>
#include <QMessageBox>

class download : public QObject
{
    Q_OBJECT
public:
    explicit download(QObject *parent = 0);
    QString down(const QUrl &url);
    void setUrl(QUrl &url);
    bool isFinish=false;
    void start();
    void stop();
signals:
    void sendCheckGoodsFinish();
public slots:
    void check();

    void stopGoodsCheck();
private slots:

private:
     bool isGetGoods=true;
    QNetworkAccessManager *manager;
    QUrl url;
     QTimer * goodsTimer;

};

#endif // DOWNLOAD_H
