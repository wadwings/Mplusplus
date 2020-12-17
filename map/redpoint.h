#include <QObject>
#include <QtWidgets>
#include <iostream>
#include <global_var.h>
using namespace std;
class redpoint : public QLabel
{
    Q_OBJECT
public:
    QTimer *timer = new QTimer();
    QWidget *w;
    vector<string> organization;
    string tip;
    redpoint(QWidget* parent);
    string loc1;
    redpoint(int x, int y, QWidget* parent, string loc1, string loc2);
    ~redpoint();
public slots:
    void over5s();
protected:
    void enterEvent(QEvent *ev) override;
    void leaveEvent(QEvent *ev) override;

signals:
     void leftClicked(string);//点击左键信号
     void rightClicked(string);//点击右键信号

protected:
     void mousePressEvent(QMouseEvent *event) override;//函数重写
};
