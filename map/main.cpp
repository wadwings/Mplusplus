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
#include <global_var.h>
#include <graph.h>
#include <map.h>
using namespace std;

routeHandler * route;
vector<QLine> lines;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    ifstream Lfs("../resources/Location.txt");//坐标
    ifstream Nfs("../resources/Locorg.txt");//坐标对应地点
    ifstream Ofs("../resources/Organization.txt");//组织对应坐标
    ifstream Efs("../resources/Edge.txt");//坐标对应边
    cout << Lfs.is_open() << endl;
    cout << Nfs.is_open() << endl;
    cout << Ofs.is_open() << endl;
    cout << Efs.is_open() << endl;
    //小红点初始化
    vector<string> organization(33);
    vector<int> loco(25);
    vector<vector <int>> position(25);
    vector<vector <int>> edge;
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
    char *t = new char(10);
    int Efs_count = 0;
    Efs.getline(t,10);
    while(*t != '\0'){
        edge.push_back(vector<int>(2));
        sscanf(t, "%d,%d", &edge[Efs_count][0], &edge[Efs_count][1]);
        Efs_count++;
        Efs.getline(t,10);
    }
    int x, y;
    Lfs >>  x >> y;
    int i = -1;
    QPixmap redpic("../resources/redpoint.png");
    QPixmap yellowpic("../resources/yellowpoint.png");
    QPixmap bluepic("../resources/bluepoint.png");
    QPixmap greenpic("../resources/greenpoint.png");
    QPixmap mappic("../resources/map.bmp");
    __map__ * map = new __map__(&w, organization, &mappic);
    map->show();
    while(y){
        position[count].push_back(x);
        position[count++].push_back(y);
        y = 0;
        Lfs >>  x >> y;
    }
    ::route = new routeHandler(organization, loco, position, &w, bluepic, yellowpic, edge, greenpic);
    while(i++ < 24){
        int c[2]{loco[i]/100, loco[i]%100};
        redpoint *r;
        if(c[0]!=0)
            r = new redpoint(position[i][0], position[i][1], &w, organization[c[0]], organization[c[1]]);
        else
            r = new redpoint(position[i][0], position[i][1], &w, organization[c[1]], "");
        r->setPixmap(redpic);
        r->show();
    }
    menu * m = new menu(&w, organization);
    m->show();
    w.show();
    return a.exec();
}
