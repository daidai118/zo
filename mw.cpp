#include "mw.h"
#include "ui_mw.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->webView,SIGNAL(urlChanged(QUrl)),this,SLOT(chgText(QUrl)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb1_clicked()
{
    this->ui->webView->load(QUrl(this->ui->lineEdit->text()));
}
void MainWindow::chgText(QUrl url){
    this->ui->lineEdit->setText(url.toString());
}

void MainWindow::on_lineEdit_returnPressed()
{
    this->ui->webView->load(QUrl(this->ui->lineEdit->text()));
}
