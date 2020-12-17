#ifndef ROUTEHANDLER_H
#define ROUTEHANDLER_H
#include <vector>
#include <string>
#include <QtWidgets>
#include <graph.h>
#include <widget.h>
using namespace std;
class routeHandler : public QLabel
{
    Q_OBJECT
public:
    WUDG* graph;
    vector<string> organization;
    vector<int> loco;
    vector<vector<int>> position;
    QLabel *begin, *end;
    QPixmap bluepoint, yellowpoint, greenpoint;
    vector<QLabel*> pathpoint;
    int beginIndex, endIndex;
    Widget* parent;
    routeHandler(vector<string> organization, vector<int> loco, vector<vector<int>> position,\
                 Widget * parent, QPixmap bluepoint, QPixmap yellowpoint, vector<vector<int>> edge, QPixmap greenpoint);
    vector<int> findposition(string d, int flag);
    void draft();
public slots:
    void setbegin(string d);
    void setend(string d);
};

#endif // ROUTEHANDLER_H
