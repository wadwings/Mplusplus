#include "close.h"
closetag::closetag(QWidget * parent, int x, int y) : QLabel(parent)
{
    this->move(x,y);
    this->setText("close");
    connect(this, SIGNAL(press()), parent, SLOT(close()));
}

void closetag::mousePressEvent(QMouseEvent *ev){
    press();
};
