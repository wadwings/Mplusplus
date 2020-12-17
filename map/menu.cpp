#include "menu.h"
menu::menu(QWidget * parent, vector<string> o) : QLabel(parent), o(o)
{
    this->setText("菜单");
    this->move(0, 0);
    this->resize(80, 20);
    this->show();
    this->setStyleSheet("background-color: white");
    this->setAlignment(Qt::AlignCenter);
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

void menu::slots_mousePressEvent(){
    if(search->isVisible()){
        search->hide();
        guide->hide();
    }else{
        search->show();
        guide->show();
    }
}

void menu::mousePressEvent(QMouseEvent *ev){
    slots_mousePressEvent();
};
