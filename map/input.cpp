#include <input.h>

input::input(QWidget *parent) : QTextEdit(parent){
    this->resize(200, 20);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
};

void input::slot_getfocus(){
    getfocus();
}

void input::slot_losefocus(){
    losefocus();
}

void input::enterEvent(QEvent *ev)
{
    slot_getfocus();
    focus = 1;
}
void input::leaveEvent(QEvent *ev)
{
    QTimer::singleShot(100, this, SLOT(slot_losefocus()));
    focus = 0;
}
