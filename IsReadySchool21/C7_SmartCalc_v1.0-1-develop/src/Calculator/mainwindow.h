#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphic.h>
#include <credit.h>

extern "C"{
#include "../logic/logic.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    Graphic *window;
    Credit *wind;
public slots:
    void takeSymbols();
private slots:
    void on_pushButto_equal_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void signal(std::string);
};
#endif // MAINWINDOW_H
