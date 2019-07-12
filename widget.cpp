#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    CheckMoney();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::ChangeMoney(int n){
    money +=n;
    ui->lcdNumber->display(QString::number(money));


    CheckMoney();
    //msg.information(nullptr, "Title", "Text");
}
void Widget::CheckMoney(){
    if(money>=100){
        ui->pb_Coffee->setEnabled(true);
    }
    else{
        ui->pb_Coffee->setEnabled(false);
    }
    if(money>=150){
        ui->pb_Tea->setEnabled(true);
    }
    else{
        ui->pb_Tea->setEnabled(false);
    }
    if(money>=200){
        ui->pb_GongCha->setEnabled(true);
    }
    else{
        ui->pb_GongCha->setEnabled(false);
    }
}
void Widget::on_pb10_clicked()
{
    ChangeMoney(10);
}

void Widget::on_pb50_clicked()
{
    ChangeMoney(50);
}

void Widget::on_pb100_clicked()
{
   ChangeMoney(100);
}

void Widget::on_pb500_clicked()
{
    ChangeMoney(500);
}

void Widget::on_pb_Coffee_clicked()
{
    ChangeMoney(-100);
    coffee++;
}

void Widget::on_pb_Tea_clicked()
{
    ChangeMoney(-150);
    tea++;
}

void Widget::on_pb_GongCha_clicked()
{
    ChangeMoney(-200);
    gongcha++;
}

void Widget::on_pb_Charge_clicked()
{
    QMessageBox msg;
    int coin_500{0};
    int coin_100{0};
    int coin_50{0};
    int coin_10{0};

    while(money>0){
        if(money>=500){
            money-=500;
            coin_500++;
            continue;
        }
        if(money>=100){
            money-=100;
            coin_100++;
            continue;
        }
        if(money>=50){
            money-=50;
            coin_50++;
            continue;
        }
        if(money>=10){
            money-=10;
            coin_10++;
            continue;
        }
    }
    QString s ="거스름돈은\n";

    s.append("500원");

    s.append(QString::number(coin_500));

    s.append("개\n");
    s.append("100원");
    s.append(QString::number(coin_100));
    s.append("개\n");
    s.append("50원");
    s.append(QString::number(coin_50));
    s.append("개\n");
    s.append("10원");
    s.append(QString::number(coin_10));
    s.append("개\n 입니다\n");

    msg.information(nullptr, "남은 돈 출금", s);
    ChangeMoney(0);
    CheckMoney();
}
