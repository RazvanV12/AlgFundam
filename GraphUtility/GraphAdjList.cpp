//
// Created by Razvan on 11/12/2024.
//
#include <limits>
#define MAX_VALUE_INT std::numeric_limits<int>::max()

#include "GraphAdjList.h"

#include <queue>

GraphAdjList::GraphAdjList(const vector<vector<int>> &adjList) {
    this->adjList = adjList;
    dad = vector<int>(adjList.size(), 0);
    visited = vector<bool>(adjList.size(), false);
    distance = vector<int>(adjList.size(), MAX_VALUE_INT);
    bfsResult = vector<int>();
}

void GraphAdjList::BFS(const int start) {
    queue<int> queue;
    queue.push(start);
    visited[start] = true;
    distance[start] = 0;
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        bfsResult.push_back(node);
        for (int i = 0; i < adjList[node].size(); i++) {
            if (!visited[adjList[node][i]]) {
                queue.push(adjList[node][i]);
                visited[adjList[node][i]] = true;
                distance[adjList[node][i]] = distance[node] + 1;
                dad[adjList[node][i]] = node;
            }
        }
    }
}

void GraphAdjList::BFS() {
    initializeValueForBFS();
    bfsResult.clear();
    for(int i = 0; i < adjList.size(); i++) {
        if(visited[i] == false)
            BFS(i);
    }
}


vector<vector<int>> GraphAdjList::getAdjList() {
    return this->adjList;
}

vector<int> GraphAdjList::getDad() {
    return this->dad;
}

vector<int> GraphAdjList::getDistance() {
    return this->distance;
}

vector<bool> GraphAdjList::getVisited() {
    return this->visited;
}

void GraphAdjList::initializeValueForBFS() {
    for (int i = 0; i < getAdjList().size(); i++) {
        this->visited[i] = false;
        this->dad[i] = 0;
        this->distance[i] = MAX_VALUE_INT;
    }
}

vector<int> GraphAdjList::getBfsResult() {
    return bfsResult;
}


