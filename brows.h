#ifndef BROWS_H
#define BROWS_H

#include <QtWidgets>

class Brows : public QWidget
{
    Q_OBJECT

private:

    QSlider* speople;
    QSlider* scost;
    QSlider* sprice;

    QLabel* lprofDay;
    QLabel* lprofMonth;
    QLabel* lpeople;
    QLabel* lcost;
    QLabel* lprice;

    QVBoxLayout* hlay;

    int profit = 0;


public:
    Brows(QWidget *parent = nullptr);
    ~Brows();

public slots:
    void setProfit();


    void setProp();
};

#endif // BROWS_H
