#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QDialog>

extern "C"{
#include "../logic/logic.h"
}
namespace Ui {
class Graphic;
}

class Graphic : public QDialog
{
    Q_OBJECT

public:
    explicit Graphic(QWidget *parent = nullptr);
    ~Graphic();

private slots:
    void on_pushButton_clicked();
public slots:
    void slot(std::string a);
private:
    Ui::Graphic *ui;
    std::string task;
    double xBegin, xEnd, h, X;
    int N;

    QVector<double> x,y;


};

#endif // GRAPHIC_H
