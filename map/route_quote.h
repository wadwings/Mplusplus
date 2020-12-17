#ifndef ROUTE_QUOTE_H
#define ROUTE_QUOTE_H
#include <QtWidgets>
#include <search_quote.h>
#include <close.h>
#include <global_var.h>
#include <routehandler.h>

class route_quote : public QWidget
{
public:
    vector<string> o;
    closetag *tag;
    searchlist *begin, *end;
    route_quote(QWidget * parent, vector<string> organization);
protected:
    virtual void mousePressEvent( QMouseEvent *e );
    virtual void mouseMoveEvent( QMouseEvent *e );
    virtual void mouseReleaseEvent( QMouseEvent *e );
private:
    bool _mousePressed;
    QPoint _mousePosition;
};

#endif ROUTE_QUOTE_H
