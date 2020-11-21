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
    launchlabel(QWidget * parent = nullptr, int type = 0, vector<string> o = {""}):QLabel(parent),o(o),type(type),w(parent){
    }
signals:
    void onmousePress();
protected:
    void mousePressEvent(QMouseEvent *ev) override{
        if(type)
            new search_quote(w, o);
        else
            new route_quote(w, o);
        onmousePress();
    };
};
