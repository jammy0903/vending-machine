#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void changeEnable();
    void changeMoney(int diff);


private slots:
    void on_pccoin10_clicked();

    void on_pcCoin50_clicked();

    void on_pcCoin100_clicked();

    void on_pccoin1000_clicked();

    void on_pbcoffee_clicked();

    void on_pbtea_clicked();

    void on_pbtang_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
