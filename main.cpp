#include <iostream>
#include "GraphUtility/GraphAdjList.h"
using namespace std;

int main()
{
    vector<vector<int>> adjList(5);
    adjList[0].push_back(1);
    adjList[0].push_back(4);
    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    adjList[2].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);
    adjList[3].push_back(2);
    adjList[3].push_back(4);
    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[4].push_back(3);
    GraphAdjList graph = GraphAdjList(adjList);
    graph.BFS(2);
    for(int i = 0; i < graph.getBfsResult().size(); i++) {
        cout << graph.getBfsResult()[i] << " ";
    }
}
