#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEnable(){

    ui->pbtang->setEnabled(money >= 200);
    ui->pbcoffee->setEnabled(money >= 100);
    ui->pbtea->setEnabled(money >= 30);

}




void Widget::changeMoney(int diff) {
     money -= diff;
    if(money>=0){
        ui->lcdnumber->display(money);
        changeEnable();

    }else if(money <0){
        money = 0;
        changeEnable();
    }
}


void Widget::on_pccoin10_clicked()
{
    money +=10;
    ui->lcdnumber->display(money);
    changeEnable();
}

void Widget::on_pcCoin50_clicked()
{
    money +=50;
    ui->lcdnumber->display(money);
    changeEnable();

}void Widget::on_pcCoin100_clicked()
{
    money +=100;
    ui->lcdnumber->display(money);
    changeEnable();
}


void Widget::on_pccoin1000_clicked()
{
    money +=1000;
    ui->lcdnumber->display(money);
    changeEnable();
}


void Widget::on_pbcoffee_clicked()
{
    changeMoney(100);
    changeEnable();
}


void Widget::on_pbtea_clicked()
{
    changeMoney(30);
    changeEnable();
}

void Widget::on_pbtang_clicked()
{
    changeMoney(200);
    changeEnable();
}
void Widget::on_pbReset_clicked()
{
    int num1 = money / 1000;
    money %= 1000;
    int num2 = money / 100;
    money %= 100;
    int num3 = money / 50;
    money %= 50;
    int num4 = money / 10;
    money %= 10;

    QMessageBox::information(nullptr, "Change", QString("1000won: %1, 100won: %2, 50won: %3, 10won: %4").arg(num1).arg(num2).arg(num3).arg(num4));
    money = 0;
    ui->lcdnumber->display(money);

}




