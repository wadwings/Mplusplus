#ifndef __SEARCHQUOTE__
#define __SEARCHQUOTE__
#include <QObject>
#include <QtWidgets>
#include <QtGui>
#include <iostream>
#include <search_list.h>
#include <close.h>

class search_quote : public QWidget {
public:
    closetag * tag;
    searchlist * list;
    search_quote(QWidget *parent = nullptr, vector<string> = {""});
protected:
    virtual void mousePressEvent( QMouseEvent *e );
    virtual void mouseMoveEvent( QMouseEvent *e );
    virtual void mouseReleaseEvent( QMouseEvent *e );

private:
    bool _mousePressed;
    QPoint _mousePosition;
};
#endif
