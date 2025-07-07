#include<bits/stdc++.h>
using namespace std;

void dfs(int stNode, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& isVisited, unordered_map<int, bool>& inDFS, bool& ans) {
    isVisited[stNode] = true;
    inDFS[stNode] = true;
    
    for(auto node: adjList[stNode]) {
        if(!isVisited[node]) {
            dfs(node, adjList, isVisited, inDFS, ans);
        } else if(inDFS[node]) { //visited node
            ans = true;
            return;
        }
    }
    inDFS[stNode] = false; //backtracking(inDFS => false while returning back)
}

bool isCyclic(int V, vector<vector<int>> &edges) {
    // code here
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }
    
    unordered_map<int, bool> isVisited;
    for(int i = 0; i < V; i++) {
        isVisited[i] = false;
    }
    
    unordered_map<int, bool> inDFS;
    for(int i = 0; i < V; i++) {
        inDFS[i] = false;
    }
    
    bool ans = false;
    //call dfs
    for(int i = 0; i < V; i++) {
        if(!isVisited[i]) {
            dfs(i, adjList, isVisited, inDFS, ans);
        }
    }
    
    return ans;
}

int main() {
    return 0;
}