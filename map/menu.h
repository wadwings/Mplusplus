#ifndef MENU_H
#define MENU_H
#include <QtWidgets>
#include <vector>
#include <string>
#include "launchlabel.h"
using namespace std;
class menu : public QLabel
{
    Q_OBJECT
public:
    QLabel *search;
    QLabel *guide;
    vector<string> o;
    menu(QWidget * parent = nullptr, vector<string> o = {""});
public slots:
    void slots_mousePressEvent();
protected:
    void mousePressEvent(QMouseEvent *ev) override;
};


#endif // MENU_H
