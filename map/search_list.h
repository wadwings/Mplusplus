#ifndef __SEARCHLIST__
#define __SEARCHLIST__
#include <QObject>
#include <QtWidgets>
#include <iostream>
#include <input.h>
using namespace std;

class searchlist : public QListWidget{
    Q_OBJECT
public:
    vector<string> organization;
    input *text;
    int focus = 0;
    searchlist() = default;
    searchlist(QWidget *parent = nullptr, vector<string> t = {0}, int x = 0, int y = 0);
public slots:
    void load_list();
    void focus_detect();
    void out_focus();
    void testOnDoubleClicked(QListWidgetItem *item);
signals:
    void send_text(string s);
private:
    int lcs_2(string str1, string str2);
    vector<int>* lcs_1(vector<string> vs, string str);
protected:
    void enterEvent(QEvent *ev) override;
    void leaveEvent(QEvent *ev) override;
};
#endif
