#include "routehandler.h"
routeHandler::routeHandler(vector<string> organization, vector<int> loco, \
                           vector<vector<int>> position, Widget * parent, \
                           QPixmap bluepoint, QPixmap yellowpoint, vector<vector<int>> edge, QPixmap greenpoint):\
                            graph(new WUDG(25, edge, position)), organization(organization), \
                            loco(loco), position(position), greenpoint(greenpoint), parent(parent){
    begin = new QLabel(parent);
    begin->move(100, 840);
    begin->resize(200,20);
    begin->show();
    end = new QLabel(parent);
    end->move(400,840);
    end->resize(200,20);
    end->show();
};
vector<int> routeHandler::findposition(string d, int flag = 0){
    int count;
    for(count = 0; count < 33; count++)
        if(organization[count] == d)
            break;
    if(count != 33){
        for(int temp = 0; temp < 25; temp++)
            if(loco[temp] / 100 == count || loco[temp] % 100 == count){
                if(flag == 1){
                    endIndex = temp;
                }else{
                    beginIndex = temp;
                }
                return position[temp];
            }
    }
    return {};
}

void routeHandler::draft(){
    for(auto e = pathpoint.begin(); e != pathpoint.end(); e++){
        delete *e;
    }
    pathpoint.clear();
    if(begin->text().toStdString().length()&&end->text().toStdString().length()){
        int temp = endIndex;
        vector<int> path = graph->Dijkstra(beginIndex, endIndex);
        while(path[temp] != -1){
            vector<int> beginPos(position[path[temp]]);
            vector<int> endPos(position[temp]);
            int divx = endPos[0] - beginPos[0];
            int divy = endPos[1] - beginPos[1];
            int dis = graph->arcs[path[temp]][temp];
            for(float i = 4; i < dis - 4; i+=2){
                QLabel * point = new QLabel(parent);
                point->setPixmap(greenpoint);
                point->resize(6,6);
                point->move(beginPos[0] + i / dis * divx - 3, beginPos[1] + i / dis * divy + 17);
                point->show();
                pathpoint.push_back(point);
            }
            temp = path[temp];
        }
        vector<int> beginPos(position[beginIndex]);
        vector<int> endPos(position[temp]);
        int divx = endPos[0] - beginPos[0];
        int divy = endPos[1] - beginPos[1];
        int dis = graph->arcs[beginIndex][temp];
        for(float i = 6; i < dis - 4; i+=2){
            QLabel * point = new QLabel(parent);
            point->setPixmap(greenpoint);
            point->resize(6,6);
            point->move(beginPos[0] + i / dis * divx - 3, beginPos[1] + i / dis * divy + 17);
            point->show();
            pathpoint.push_back(point);
        }
    }
};
void routeHandler::setbegin(string d){
    findposition(d);
    if(begin->text().toStdString() == d){
        begin->setText("");
    }else if(end->text().toStdString() == d){
        end->setText("");
    }else{
        begin->setText(d.c_str());
    }
    draft();
}

void routeHandler::setend(string d){
    findposition(d, 1);
    if(end->text().toStdString() == d){
        end->setText("");
    }else if(begin->text().toStdString() == d){
        begin->setText("");
    }else{
        end->setText(d.c_str());
    }
    draft();
}
