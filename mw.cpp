#include "mw.h"
#include "ui_mw.h"
#include "download.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->page()->networkAccessManager()->setCookieJar(network_cookie);
//    QList<QNetworkCookie> cookies = network_cookie_.getCookies();
    connect(ui->webView,SIGNAL(urlChanged(QUrl)),this,SLOT(chgText(QUrl)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init(){
    down.moveToThread(&downThread);
    connect(&downThread, SIGNAL(finished()), &down, SLOT(deleteLater()));

    downThread.start();

}
//http://app_api.fuhui.com/
//http://zozo.jp/category/suit/suit-jacket/
void MainWindow::on_pb1_clicked()
{
    ui->webView->load(QUrl(ui->lineEdit->text()));
}
void MainWindow::chgText(QUrl url){
    QString utxt = url.toString();
    if(utxt != "about:blank"){
        this->ui->lineEdit->setText(url.toString());
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    ui->webView->load(QUrl(ui->lineEdit->text()));
}


void MainWindow::startRequest(QUrl url)
{
    down.setUrl(url);
    down.start();
    QMessageBox::information(this,"","开始");
}



void MainWindow::on_pb1_2_clicked()
{
    QUrl url = ui->lineEdit->text();
    startRequest(url);
}



void MainWindow::on_pb1_3_clicked()
{
    down.stop();
}
