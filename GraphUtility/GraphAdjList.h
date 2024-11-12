//
// Created by Razvan on 11/12/2024.
//

#ifndef GRAPHADJLIST_H
#define GRAPHADJLIST_H
#include <vector>
using namespace std;



class GraphAdjList {
    vector<vector<int>> adjList;
    vector<int> dad;
    vector<int> distance;
    vector<bool> visited;
    vector<int> bfsResult;

public:
    explicit GraphAdjList(const vector<vector<int>> &adjList);
    void BFS(int start);
    void BFS();
    vector<vector<int>> getAdjList();
    vector<int> getDad();
    vector<int> getDistance();
    vector<bool> getVisited();
    vector<int> getBfsResult();

private:
    void initializeValueForBFS();
};



#endif //GRAPHADJLIST_H
