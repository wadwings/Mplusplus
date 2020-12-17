#include <route_quote.h>

route_quote::route_quote(QWidget * parent, vector<string> organization):QWidget(parent), o(organization)\
                        /*, route(new routeHandler(organization, loco, position, parent, bluepoint, yellowpoint))*/{
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
    QObject::connect(begin, SIGNAL(send_text(string)), route, SLOT(setbegin(string)));
    QObject::connect(end, SIGNAL(send_text(string)), route, SLOT(setend(string)));
};

void route_quote::mousePressEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = true;
        _mousePosition = e->pos();
    }
}

void route_quote::mouseMoveEvent( QMouseEvent *e )
{
    if ( _mousePressed ) {
        move( mapToParent( e->pos() - _mousePosition ) );
    }
}

void route_quote::mouseReleaseEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = false;
        _mousePosition = QPoint();
    }
}
