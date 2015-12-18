#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QTextCodec>
#include <QTime>
#include <regex>
#include <QString>
#include <QMessageBox>
#include <QByteArray>
#include <QThread>
#include <QTimer>
#include "download.h"
#include "webdiycookie.h"
//typedef std::list<QString> SL;
//typedef std::match_results<std::wstring::const_iterator> wsmatch;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startRequest(QUrl url);

    QThread downThread;
    void init();
    WebDiyCookie *network_cookie;

public slots:

private slots:
    void on_pb1_clicked();
    void chgText(QUrl);

    void on_lineEdit_returnPressed();

    void on_pb1_2_clicked();

    
    void on_pb1_3_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray *buf;
    download down;

    QTimer *goodsTimer;
    QUrl url;

};

#endif // MW_H
