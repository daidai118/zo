#include "mw.h"
#include "ui_mw.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
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
    QString utxt = url.toString();
    if(utxt != "about:blank"){
        this->ui->lineEdit->setText(url.toString());
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    this->ui->webView->load(QUrl(this->ui->lineEdit->text()));
}


void MainWindow::startRequest(QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));

    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(updateDataReadProgress(qint64,qint64)));

    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
}

void MainWindow::httpReadyRead()
{
    reply->readAll();
}


void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}

void MainWindow::httpFinished()
{
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}

void MainWindow::on_pb1_2_clicked()
{
    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    if (fileName.isEmpty()) fileName = "index.html";
    file = new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug() << "file open error";
        delete file;
        file = 0;
        return;
    }
    startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}
