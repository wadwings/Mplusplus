#include <vector>
#include <string>
#include <QtWidgets>
#ifndef ROUTEHANDLER_H
#define ROUTEHANDLER_H

using namespace std;
class routeHandler
{
public:
    vector<string> organization;
    vector<int> loco;
    QLabel *begin, *end;
    routeHandler(vector<string> organization, vector<int> loco, int**position);
    void setbegin(string d){

    }
};

#endif // ROUTEHANDLER_H
