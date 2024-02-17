#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <iostream>
#include <QPushButton>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_number_0, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_1, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_2, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_3, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_4, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_5, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_6, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_7, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_8, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_number_9, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_min, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_close_breaket, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_open_breaket, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_root, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(takeSymbols()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(takeSymbols()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::takeSymbols()
{
    QPushButton *button = (QPushButton *)sender();
    ui->label->setText(ui->label->text() + button->text());
}




void MainWindow::on_pushButto_equal_clicked()
{
    long double res = 0;
    int error = 0;
    int x_true = 0;
    double x = 0;
    std::string str_x = ui->lineEdit->text().toStdString();
    std::string str = ui->label->text().toStdString();

    if(str_x != ""){
        int con_dot = 0;
        for(size_t i = 0; i < str_x.length(); i++){
            if(str_x[0] == '-' || str_x[0] == '+'){
                 continue;
            }
            if((str_x[i] >= '0' && str_x[i] <= '9') || str_x[i] == '.'){
                if(str_x[i] == '.'){
                    con_dot++;
                }
                continue;
            }

            error = 1;
        }
        if(con_dot > 1){
            error = 1;
        }

        if(!error){
            if(str_x == "."){
                x = 0;
            } else{
                x = stod(str_x);
            }
            x_true = 1;
        }
    }

    for(size_t i = 0; i < str.length(); i++){
        if(str[i] == 'x'){
            if(!x_true){
                error = 1;
            }
        }
    }

    if(error){
       ui->label->setText("Error input");
       ui->lineEdit->setText("");
       return;
    }

    if(str.size() > 254){
        ui->label->setText("Error input");
    } else{
        char *str_ptr = &str[0];
        error = validate(str_ptr);
        if(!error){
            str_ptr = polish_notation(str_ptr);
            res = calculation(str_ptr, x, x_true, &error);
            if(error){
               ui->label->setText("Error input");
               ui->lineEdit->setText("");
               return;
            }
            ui->label->setText(QString::number(res, 'f', 6));
            ui->lineEdit->setText("");
            delete str_ptr;
        } else{
            ui->label->setText("Error input");
            ui->lineEdit->setText("");
        }
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText("");
}


void MainWindow::on_pushButton_clicked()
{
    window = new Graphic();
    connect(this, &MainWindow::signal, window, &Graphic::slot);
    emit signal(ui->label->text().toStdString());

    window->show();
}


void MainWindow::on_pushButton_3_clicked()
{
   QString str = ui->label->text();
   str.chop(1);
   ui->label->setText(str);
}


void MainWindow::on_pushButton_4_clicked()
{
    wind = new Credit();
    wind->show();
}

