#ifndef MENU_H
#define MENU_H
#include <QtWidgets>
#include <vector>
#include <string>
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
    void slots_mousePressEvent(){
            if(search->isVisible()){
            search->hide();
            guide->hide();
        }else{
            search->show();
            guide->show();
        }
    }
protected:
    void mousePressEvent(QMouseEvent *ev) override{
        slots_mousePressEvent();
    };
};


#endif // MENU_H
