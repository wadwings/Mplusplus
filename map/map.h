#ifndef MAP_H
#define MAP_H
#include <QObject>
#include <QtGui>
#include <menu.h>

class __map__ : public QLabel
{
    Q_OBJECT
public:
    QLabel *search;
    QLabel *guide;
    vector<string> o;
    __map__(QWidget * parent = nullptr, vector<string> o = {""}, QPixmap * mappic = nullptr);
public slots:
    void slots_mousePressEvent();
    void slots_closemenu();
protected:
    void mousePressEvent(QMouseEvent *ev) override;
};

#endif // MAP_H
