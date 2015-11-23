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
typedef std::list<QString> SL;
typedef std::match_results<std::wstring::const_iterator> wsmatch;

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

public slots:

private slots:
    void on_pb1_clicked();
    void chgText(QUrl);

    void on_lineEdit_returnPressed();
    void httpFinished();
    void httpReadyRead();

    void on_pb1_2_clicked();
    
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;
};

#endif // MW_H
