#include "launchlabel.h"

launchlabel::launchlabel(QWidget * parent, int type = 0, vector<string> o = {""})\
    :QLabel(parent),o(o),type(type),w(parent){
};
void launchlabel::mousePressEvent(QMouseEvent *ev){
    if(type)
        new search_quote(w, o);
    else
        new route_quote(w, o);
    onmousePress();
};
