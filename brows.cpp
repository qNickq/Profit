#include "brows.h"

Brows::Brows(QWidget *parent)
    : QWidget(parent)
{
    //Sliders
    speople = new QSlider(Qt::Horizontal);
    scost = new QSlider(Qt::Horizontal);
    sprice = new QSlider(Qt::Horizontal);

    speople->setObjectName("speople");
    scost->setObjectName("scost");
    sprice->setObjectName("sprice");

    //Labels
    lpeople = new QLabel("Кол-во людей в день: 1");
    lcost = new QLabel("Себестоимость процедуры: 0");
    lprice = new QLabel("Цена за процедуру: 50");

    //People
    speople->setRange(1,10);
    speople->setValue(1);
    speople->setTickInterval(1);
    speople->setTickPosition(QSlider::TicksBelow);

    //Cost
    scost->setRange(0,10);
    scost->setValue(0);
    scost->setTickInterval(1);
    scost->setTickPosition(QSlider::TicksBelow);

    //Price
    sprice->setRange(1,20);
    sprice->setValue(1);
    sprice->setSingleStep(10);
    sprice->setTickInterval(100);
    sprice->setTickPosition(QSlider::TicksBelow);

    //Profit
    profit = (speople->value() * sprice->value()*50) - (speople->value() * scost->value()*50);
    lprofDay = new QLabel(QString("Чистая прибыль за день: %1").arg(profit));
    lprofMonth = new QLabel(QString("Чистая прибыль за месяц: %1").arg(profit*30));
    //Signals
    connect(speople, SIGNAL(valueChanged(int)), SLOT(setProp()));
    connect(sprice, SIGNAL(valueChanged(int)), SLOT(setProp()));
    connect(scost, SIGNAL(valueChanged(int)), SLOT(setProp()));

    connect(speople, SIGNAL(valueChanged(int)), SLOT(setProfit()));
    connect(sprice, SIGNAL(valueChanged(int)), SLOT(setProfit()));
    connect(scost, SIGNAL(valueChanged(int)), SLOT(setProfit()));

    //Layout
    hlay = new QVBoxLayout;
    hlay->addWidget(lpeople);
    hlay->addWidget(speople);
    hlay->addWidget(lcost);
    hlay->addWidget(scost);
    hlay->addWidget(lprice);
    hlay->addWidget(sprice);
    hlay->addWidget(lprofDay);
    hlay->addWidget(lprofMonth);
    this->setLayout(hlay);

}
void Brows::setProp()
{

    if(sender()->objectName() == "speople")
    {
        lpeople->setText(QString("Кол-во людей в день: %1").arg(speople->value()));
    }
    else if (sender()->objectName() == "scost")
    {

        lcost->setText(QString("Себестоимость процедуры: %1").arg(scost->value()*50));

    }
    else if (sender()->objectName() == "sprice")
    {
        lprice->setText(QString("Цена за процедуру: %1").arg(sprice->value()*50));
    }
}

void Brows::setProfit()
{
    profit = (speople->value() *sprice->value()*50) - (speople->value()*scost->value()*50);
    lprofDay->setText(QString("Чистая прибыль за день: %1").arg(profit));
    lprofMonth->setText(QString("Чистая прибыль за месяц: %1").arg(profit*30));
}

Brows::~Brows()
{

}
