#include <iostream>
#include <vector>
#include <math.h>
#ifndef __GRAPH__
#define __GRAPH__
using namespace std;

class WUDG
{
public:
    WUDG(int vexNum, vector<vector<int>> edge, vector<vector<int>> position);
    vector<int> Dijkstra(int begin, int end);
    vector<vector <int>> arcs;    //邻接矩阵
private:
    vector<int> vvec;          //顶点向量
    int vexnum;                       //图的当前顶点个数
};
#endif
