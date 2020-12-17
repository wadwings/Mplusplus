#ifndef __LAUNCHLABEL__
#define __LAUNCHLABEL__
#include <menu.h>
#include <search_quote.h>
#include <route_quote.h>
using namespace std;
class launchlabel : public QLabel{
    Q_OBJECT
public:
    vector<string> o;
    int type;
    QWidget * w;
    launchlabel(QWidget * parent, int type, vector<string> o);
signals:
    void onmousePress();
protected:
    void mousePressEvent(QMouseEvent *ev) override;
};
#endif
