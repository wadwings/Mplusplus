#include <QObject>
#include <QtWidgets>
#include <iostream>
using namespace std;
class redpoint : public QLabel
{
    Q_OBJECT
public:
    QTimer *timer = new QTimer();
    QWidget *w;
    vector<string> organization;
    string tip;
    redpoint(QWidget* parent = nullptr) : QLabel(parent), w(parent){
    };
    redpoint(int x, int y, QWidget* parent = nullptr, string loc1 = "nullptr", string loc2 = "") : QLabel(parent), w(parent), organization(2){
        organization = {loc1,loc2};
        tip = loc2.length() ? loc1 + '\n' + loc2 : loc1;
        this->resize(6,6);
        this->move(x - 3,y + 17);
        connect(timer, SIGNAL(timeout()), this, SLOT(over5s()));
    };
    ~redpoint(){
        timer->~QTimer();
        this->QLabel::~QLabel();
    }
public slots:
    void over5s(){
        cout << "end" << endl;
        QToolTip::showText(w->pos() + this->pos() - QPoint(0, 30), tip.c_str(), w);
        timer->stop();
    };
protected:
    void enterEvent(QEvent *ev) override
    {
        timer->start(5000);
    }

    void leaveEvent(QEvent *ev) override
    {
        timer->stop();
    }

};
