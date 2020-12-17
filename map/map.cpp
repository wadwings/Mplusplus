#include "map.h"
__map__::__map__(QWidget * parent, vector<string> o, QPixmap * mappic) : QLabel(parent), o(o){
    this->setPixmap(*mappic);
    this->move(0,20);
    this->resize(1676, 820);
    search = new launchlabel(parent, 1, o);
    search->setText("搜索");
    search->resize(80, 20);
    search->move(0, 20);
    search->setStyleSheet("background-color: white");
    search->setAlignment(Qt::AlignCenter);
    search->hide();
    guide = new launchlabel(parent, 0, o);
    guide->setText("路径");
    guide->resize(80, 20);
    guide->move(0, 40);
    guide->setStyleSheet("background-color: white");
    guide->setAlignment(Qt::AlignCenter);
    guide->hide();
    connect(search, SIGNAL(onmousePress()), this, SLOT(slots_mousePressEvent()));
    connect(guide, SIGNAL(onmousePress()), this, SLOT(slots_mousePressEvent()));
}

void __map__::slots_mousePressEvent(){
    if(search->isVisible()){
        search->hide();
        guide->hide();
    }else{
        search->raise();
        search->show();
        guide->raise();
        guide->show();
    }
}

void __map__::mousePressEvent(QMouseEvent *ev){
    if(ev->button() == Qt::RightButton)
    {
        search->move(ev->x(), ev->y() + 20);
        guide->move(ev->x(), ev->y() + 40);
        emit slots_mousePressEvent();
    }else{
        emit slots_closemenu();
    }
};

void __map__::slots_closemenu(){
    search->hide();
    guide->hide();
}
