#include "graphic.h"
#include "ui_graphic.h"


Graphic::Graphic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphic)
{
    ui->setupUi(this);

    ui->widget->xAxis->setRange(-10,10);
    ui->widget->yAxis->setRange(-10,10);

}

Graphic::~Graphic()
{
    delete ui;
}


void Graphic::on_pushButton_clicked()
{
    double x1, x_end, y1, y_end;
    x1 = ui->lineEdit_X->value();
    x_end = ui->lineEdit_X2->value();
    if(x1 >= x_end){
        return;
    }
    y1 = ui->lineEdit_Y->value();
    y_end = ui->lineEdit_Y2->value();
    if(y1 >= y_end){
        return;
    }
    ui->widget->xAxis->setRange(x1, x_end);
    ui->widget->yAxis->setRange(y1 ,y_end);

    long double Y = 0;
    char *res_str = nullptr;
    int error = 0;
    error = validate(&task[0]);
    if(error){
        return;
    }
    h = 0.1;
    xBegin = x1;
    xEnd = x_end + h;
    N = (xEnd - xBegin) / h + 2;
    for(X = xBegin;X<= xEnd; X+=h){
        x.push_back(X);
        res_str = polish_notation(&task[0]);
        Y = calculation(res_str, X, 1, &error);
        if(error){
            return;
        }
        y.push_back(Y);
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
}

void Graphic::slot(std::string a)
{

    task = a;
    long double Y = 0;
    char *res_str = nullptr;
    int error = 0;

    error = validate(&task[0]);
    if(error){
        return;
    }
    h = 0.1;
    xBegin = -10;
    xEnd = 10 + h;
    N = (xEnd - xBegin) / h + 2;
    for(X = xBegin;X<= xEnd; X+=h){
        x.push_back(X);
        res_str = polish_notation(&task[0]);
        Y = calculation(res_str, X, 1, &error);
        if(error){
            return;
        }
        y.push_back(Y);
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
}

int checkStrX(std::string a){
    int error = 0;
    for(size_t i = 0; i < a.length();i++){
        if(a[i] == 'x'){
            error = 1;
        }
    }
    return error;
}
