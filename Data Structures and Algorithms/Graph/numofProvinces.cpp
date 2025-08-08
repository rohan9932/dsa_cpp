#include<bits/stdc++.h>
using namespace std;

/*
    Leetcode 547 : https://leetcode.com/problems/number-of-provinces/description/
*/

void dfs(int currNode, unordered_map<int, list<int>> adjList, vector<bool>& isVisited) {
    isVisited[currNode] = true;
    for(auto neighbour: adjList[currNode]) {
        if(!isVisited[neighbour]) {
            dfs(neighbour, adjList, isVisited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    unordered_map<int, list<int>> adjList;
    int n = isConnected.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i != j) && isConnected[i][j] == 1) {
                adjList[i+1].push_back(j+1);
            }
        }
    }
    vector<bool> isVisited(n+1, false);
    int provinces = 0;
    for(int i = 1; i <= n; i++) {
        if(!isVisited[i]) {
            dfs(i, adjList, isVisited);
            provinces++; //update number of components
        }
    }
    return provinces;
}

int main() {
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected) << endl;
    return 0;
}