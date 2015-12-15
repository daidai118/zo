#include "mw.h"
#include "ui_mw.h"
#include "download.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->webView,SIGNAL(urlChanged(QUrl)),this,SLOT(chgText(QUrl)));
}

MainWindow::~MainWindow()
{
    delete ui,buf;
}
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
    auto cc = down->down(url);
    QMessageBox::information(this,"",cc);
}


void MainWindow::on_pb1_2_clicked()
{
    QUrl url = ui->lineEdit->text();
    startRequest(url);
}

