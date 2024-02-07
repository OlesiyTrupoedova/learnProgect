#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>

namespace Ui {
class Credit;
}

class Credit : public QDialog
{
    Q_OBJECT

public:
    explicit Credit(QWidget *parent = nullptr);
    ~Credit();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Credit *ui;
    double credit;
    int dedline;
    double procent;
};

#endif // CREDIT_H
