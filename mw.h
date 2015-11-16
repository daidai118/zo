#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:

private slots:
    void on_pb1_clicked();
    void chgText(QUrl);

    void on_lineEdit_returnPressed();
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64, qint64);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
};

#endif // MW_H
