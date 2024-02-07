#include "credit.h"
#include "ui_credit.h"

double diff(double credit, int month, double procent, double cd);

Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}


void Credit::on_pushButton_3_clicked()
{
    double payment, repayment, overpayment;
    credit = ui->lineEdit->value();
    procent = ui->lineEdit_2->value();
    dedline = ui->lineEdit_3->value();

        payment = credit * ((procent / (100*12)) / (1 - std::pow(1+(procent / (100*12)), -dedline)));
        ui->payment->setText(QString::number(payment, 'f', 2));

        repayment = payment * dedline;
        ui->repayment->setText(QString::number(repayment, 'f', 2));

        overpayment = repayment - credit;
        ui->overpayment->setText(QString::number(overpayment, 'f', 2));

}


void Credit::on_pushButton_clicked()
{
    int month = 1;
    double payment = 0, repayment = 0, overpayment = 0;

    credit = ui->lineEdit_4->value();
    procent = ui->lineEdit_5->value();
    dedline = ui->lineEdit_6->value();
    month = ui->lineEdit_7->value();

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(dedline);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "month" << "payment");
    double cd = credit / dedline;
    double cr_p = credit;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            if(j == 0){
                QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(month));
                ui->tableWidget->setItem(i,j, tbl);
                month++;
                if(month == 13){
                    month = 1;
                }
                continue;
            }
            int m = month - 1;
            if(m == 0){
                m = 12;
            }
            payment = std::floor(diff(cr_p, m, procent, cd));
            repayment += payment;
            QTableWidgetItem *tbl_2 = new QTableWidgetItem((QString::number(payment, 'f', 6)));
            ui->tableWidget->setItem(i,j, tbl_2);
            cr_p -= cd;
        }
    }
    ui->label_11->setText(QString::number(repayment, 'f', 6));
    overpayment = repayment - credit;
    ui->label_10->setText(QString::number(overpayment, 'f', 6));
}

double diff(double credit, int month, double procent, double cd){
    std::map<int, int> monthDay;
    for(int i = 1; i <= 12; i++){
        if(i == 2){
            monthDay[i] = 28;
            continue;
        }
        if(i == 4 || i == 6 || i == 9 || i == 11){
            monthDay[i] = 30;
            continue;
        }
        monthDay[i] = 31;
    }

    double cp = (credit * (procent / 100) * monthDay[month]) / 365;
    return cd + cp;
}
