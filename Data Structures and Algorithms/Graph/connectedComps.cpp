#include<bits/stdc++.h>
using namespace std;

/*
    Problem: Connected components in an undirected graph
    Problem Link: https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
*/

void dfs(int currNode, unordered_map<int, list<int>>& adjList, vector<bool>& isVisited, vector<int>& temp) {
    isVisited[currNode] = true;
    temp.push_back(currNode);
    for(auto neighbour: adjList[currNode]) {
        if(!isVisited[neighbour]) {
            dfs(neighbour, adjList, isVisited, temp);
        }
    }
}

vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    // code here
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<bool> isVisited(V, false);
    vector<vector<int>> ans;
    
    for(int i = 0; i < V; i++) {
        if(!isVisited[i]) {
            vector<int> temp;
            dfs(i, adjList, isVisited, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main() {
    int V = 7;
    vector<vector<int>> edges = {{0, 1}, {6, 0}, {2, 4}, {2, 3}, {3, 4}};
    
    vector<vector<int>> components = getComponents(V, edges);
    for(auto row: components) {
        for(auto val: row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    
    return 0;
}