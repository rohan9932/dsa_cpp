#include<bits/stdc++.h>
using namespace std;

void dfs(int stNode, vector<bool>&isVisited, unordered_map<int, list<int>>& adjList, vector<int>& parent, vector<int>& dt, vector<int>& lowestDt, bool& isBridge, int& c, int& d, int& time) {
    //1.Initialize dt and lowestdt
    isVisited[stNode] = true;
    dt[stNode] = lowestDt[stNode] = ++time;
    for(auto neighbour: adjList[stNode]) {
        //2.Checking and processing before entering neighbour
        //not visited node => enter it by dfs
        if(!isVisited[neighbour]) {
            parent[neighbour] = stNode;
            dfs(neighbour, isVisited, adjList, parent, dt, lowestDt, isBridge, c, d, time);
            //update lowestDt after returning from the child node
            lowestDt[stNode] = min(lowestDt[stNode], lowestDt[neighbour]);
            //condition check for bridge
            if(dt[stNode] < lowestDt[neighbour]) {
                isBridge = isBridge || ((stNode == c) && (neighbour == d)) || ((stNode == d) && (neighbour == c));
            }
        } 
        //Back edge case => update the lowestDt
        else if (neighbour != parent[stNode]) {
            lowestDt[stNode] = min(lowestDt[stNode], dt[neighbour]);
        }
    }
}

bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
    // Code here
    //1. Adj List
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    //2. Initialize DS
    vector<bool>isVisited(V, false);
    vector<int> parent(V, -1);
    vector<int> dt(V);
    vector<int> lowestDt(V);
    bool isBridge = false;

    int time = 0;
    
    //3.DFS
    for(int i = 0; i < V; i++) {   
        if(!isVisited[i]) {
            dfs(i, isVisited, adjList, parent, dt, lowestDt, isBridge, c, d, time);
        }
    }       
    
    return isBridge;
}

int main() {

return 0;
}