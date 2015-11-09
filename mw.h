#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include <QUrl>
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

private:
    Ui::MainWindow *ui;
};

#endif // MW_H