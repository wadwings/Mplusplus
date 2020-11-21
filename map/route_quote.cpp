#include <route_quote.h>

route_quote::route_quote(QWidget * parent, vector<string> o):QWidget(parent), o(o){
    this->resize(600,250);
    this->setStyleSheet("background-color: white");
        this->move((parent->width() - 600) / 2, (parent->height() - 250) / 2);
    this->show();
    begin = new searchlist(this, o, 50, 50);
    end = new searchlist(this, o, 350, 50);
    tag = new closetag(this, 550, 20);
    QLabel * label = new QLabel(this);
    label->setText("路径");
    label->move(290, 20);
    label->show();
    label = new QLabel(this);
    label->setText(">>>>");
    label->move(290, 54);
    label->show();
    tag->show();
    begin->show();
    end->show();
};
