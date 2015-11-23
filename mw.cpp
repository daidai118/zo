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
    reply = manager->get(QNetworkRequest(url));
    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
}

void MainWindow::httpReadyRead()
{
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");

    file&&file->write(codec->toUnicode(reply->readAll().data()).toLocal8Bit());
//    const std::regex ru("\\d+");
//    wsmatch result;
//    std::regex_match("123daa11",result,ru);
    std::basic_string<char> context ="playjokes (playjokes@gmail.com)";

        std::regex mail_regex("(\\w+)@(\\w+)\\.com");
        std::wsmatch mail_result;

        // 不能全词匹配 regex_match返回false
        std::regex_match(*context, mail_result, mail_regex);
    auto c=1;
}



void MainWindow::httpFinished()
{
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}

void MainWindow::on_pb1_2_clicked()
{
    QUrl url = ui->lineEdit->text();
    QFileInfo info(url.path());
    auto fileName(info.fileName());
    QTime *cc = new QTime();
    if (fileName.isEmpty()) fileName = cc->currentTime().toString("hhmmsszzz");
    file = new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug() << "file open error";
        delete file;
        file = 0;
        return;
    }
    startRequest(url);
}
