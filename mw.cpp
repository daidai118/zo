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
    buf = new QByteArray("");
    reply = manager->get(QNetworkRequest(url));
    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
}

void MainWindow::httpReadyRead()
{
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    auto bbf = codec->toUnicode(reply->readAll().data()).toUtf8();
    buf->append(bbf);
    file&&file->write(bbf);
}


void MainWindow::httpFinished()
{
    auto str = buf->toStdString();
    const std::regex pattern("(その他)");
    bool valid = std::regex_search(str, pattern);
    if (valid){
        QMessageBox::information(this,"1","c");
    }else{
        QMessageBox::information(this,"1","失败");
    }
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    delete buf;
    file = 0;
}
//void MainWindow::httpFinished()
//{
//    auto str = buf->toStdString();
//    const std::regex pattern("その他");
//    std:: match_results<std::string::const_iterator> result;
//    bool valid = std::regex_match(str, result, pattern);
//    if (valid){
//        QMessageBox::information(this,"1","c");
//    }else{
//        QMessageBox::information(this,"1","失败");
//    }
//    file->flush();
//    file->close();
//    reply->deleteLater();
//    reply = 0;
//    delete file;
//    delete buf;
//    file = 0;
//}

void MainWindow::on_pb1_2_clicked()
{
    QUrl url = ui->lineEdit->text();
    QFileInfo info(url.path());
    auto fileName(info.fileName());
    QTime *cc = new QTime();
    if (fileName.isEmpty()) fileName = cc->currentTime().toString("hhmmsszzz");
    file = new QFile(fileName);
    if(!file->open(QIODevice::ReadWrite))
    {
        qDebug() << "file open error";
        delete file;
        file = 0;
        return;
    }
    startRequest(url);
}

