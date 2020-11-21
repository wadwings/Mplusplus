#include "widget.h"
#include <QObject>
#include <QtWidgets>
#include <QApplication>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <redpoint.h>
#include <menu.h>
using namespace std;

int find_index(vector<string>, string){
    return 0;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    ifstream Lfs("../resources/Location.txt");//坐标
    ifstream Nfs("../resources/Locorg.txt");//坐标对应地点
    ifstream Ofs("../resources/Organization.txt");//组织对应坐标
    ifstream Efs("../resouces/Edge.text");//坐标对应边
    //小红点初始化
    vector<string> organization(33);
    vector<int> loco(25);
    int dis[25][2];
    int count = 0;
    for(int i = 0;i < 33; i++)
        Ofs >> organization.at(i);
    for(int i = 0; i < 25; i++){
        char t[10];
        Nfs.getline(t, 10);
        string temp(t);
        istringstream it(temp);
        it >> loco[i];
        if(it >> t[0], *t == ','){
            int temp;
            it >> temp;
            loco.at(i) += 100*temp;
        }
    }
    int x, y;
    Lfs >>  x >> y;
    int i = -1;
    while(y){
        int c[2]{loco[++i]/100, loco[i]%100};
        redpoint *r;
        if(c[0]!=0)
            r = new redpoint(x, y, &w, organization[c[0]], organization[c[1]]);
        else
            r = new redpoint(x, y, &w, organization[c[1]]);
        QPixmap redpic("../resources/redpoint.png");
        QPixmap yellowpic("../resources/yellowpoint.png");
        QPixmap greenpic("../resources/greenpoint.png");
        r->setPixmap(redpic);
        r->show();
        y = 0;
        dis[count--][1] = y;
        dis[count++][0] = x;
        Lfs >>  x >> y;
    }
    menu * m = new menu(&w, organization);
    m->show();
    //
    w.show();
    return a.exec();
}
