#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void ChangeMoney(int n);
    void CheckMoney();
    int money{0};
    int coffee{0};
    int tea{0};
    int gongcha{0};

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pb_Coffee_clicked();

    void on_pb_Tea_clicked();

    void on_pb_GongCha_clicked();

    void on_pb_Charge_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
