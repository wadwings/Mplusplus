#include "redpoint.h"

redpoint::redpoint(QWidget* parent) : QLabel(parent), w(parent){};

redpoint::redpoint(int x, int y, QWidget* parent = nullptr, string loc1 = "nullptr", string loc2 = "") : QLabel(parent), w(parent), organization(2), loc1(loc1){
    organization = {loc1,loc2};
    tip = loc2.length() ? loc1 + '\n' + loc2 : loc1;
    this->resize(6,6);
    this->move(x - 3,y + 17);
    connect(timer, SIGNAL(timeout()), this, SLOT(over5s()));
    QObject::connect(this, SIGNAL(leftClicked(string)), route, SLOT(setbegin(string)));
    QObject::connect(this, SIGNAL(rightClicked(string)), route, SLOT(setend(string)));
};

redpoint::~redpoint(){
    timer->~QTimer();
    this->QLabel::~QLabel();
}

void redpoint::over5s(){
    cout << "end" << endl;
    QToolTip::showText(w->pos() + this->pos() - QPoint(0, 30), tip.c_str(), w);
    timer->stop();
};

void redpoint::enterEvent(QEvent *ev)
{
    timer->start(5000);
}

void redpoint::leaveEvent(QEvent *ev)
{
    timer->stop();
}


void redpoint::mousePressEvent(QMouseEvent *event)
{
    // 如果是鼠标左键按下
    if(event->button() == Qt::LeftButton)
   {
        emit leftClicked(loc1);
    }
    // 如果是鼠标右键按下
    else if(event->button() == Qt::RightButton)
    {
       emit rightClicked(loc1);
    }
}
