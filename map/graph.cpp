#include <graph.h>
WUDG::WUDG(int vexNum, vector<vector<int>> edge, vector<vector<int>> position) :  vvec(vexNum), arcs(vexNum), vexnum(vexNum)
{
    for (int i = 0; i < vexnum; i++)
    {
        //为每一行动态分配空间
        arcs[i] = vector<int>(vexnum);
    }
    for (auto e = edge.begin(); e!=edge.end(); e++){
        int distance = sqrt(pow(position[e->at(0)][0] - position[e->at(1)][0], 2) + pow(position[e->at(0)][1] - position[e->at(1)][1], 2));
        arcs[e->at(0)][e->at(1)] = distance;
        arcs[e->at(1)][e->at(0)] = distance;
    }
}

vector<int> WUDG::Dijkstra(int begin, int end){
    vector<int> dis(25), path(25, -1);
    vector<vector <int>> temp_arcs(arcs);
    if(begin < 25 && end < 25){
        for(auto e = dis.begin(); e != dis.end(); e++){
            *e = 99999;
        }
        dis[begin] = 0;
        vector<int> a(25);
        a[begin] = 1;
        while(!a[end]){
            int count = 0, min = 9999;
            for(int i = 0; i < 25; i++){
                if(!a[i]&&temp_arcs[begin][i]!=0&&temp_arcs[begin][i] < min){
                    min = temp_arcs[begin][i];
                    count = i;
                }
            }
            a[count] = 1;
            dis[count] = temp_arcs[begin][count];
            for(int i = 0; i < 25; i++){
                if(temp_arcs[count][i] != 0 && ((temp_arcs[begin][i] > temp_arcs[begin][count] + temp_arcs[count][i])||!temp_arcs[begin][i])){
                    path[i] = count;
                    temp_arcs[begin][i] = temp_arcs[begin][count] + temp_arcs[count][i];
                    temp_arcs[i][begin] = temp_arcs[begin][count] + temp_arcs[count][i];
                }
            }
        }
    }
    return path;
}
