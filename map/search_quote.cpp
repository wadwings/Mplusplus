#include "search_quote.h"

search_quote::search_quote(QWidget * parent, vector<string> t) : QWidget(parent)
{
    this->resize(400,250);
    this->setStyleSheet("background-color: white");
    this->move((parent->width() - 400) / 2, (parent->height() - 250) / 2);
    this->show();
    list = new searchlist(this, t, 100, 50);
    tag = new closetag(this, 350, 20);
    QLabel * label = new QLabel(this);
    label->setText("搜索");
    label->move(180, 20);
    label->show();
    tag->show();
}

void search_quote::mousePressEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = true;
        _mousePosition = e->pos();
    }
}

void search_quote::mouseMoveEvent( QMouseEvent *e )
{
    if ( _mousePressed ) {
        move( mapToParent( e->pos() - _mousePosition ) );
    }
}

void search_quote::mouseReleaseEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = false;
        _mousePosition = QPoint();
    }
}
