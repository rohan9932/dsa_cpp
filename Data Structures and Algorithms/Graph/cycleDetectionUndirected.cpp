#include<bits/stdc++.h>
using namespace std;

void bfs(int stNode, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& isVisited, bool& ans) {
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(stNode);
    parent[stNode] = -1;
    isVisited[stNode] = true;
    
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        //now check for adjacent nodes if the are visited but not parent
        //Y -> cycle detected
        //else move forward
        for(int node: adjList[frontNode]) {
            if(isVisited[node] == true && node != parent[frontNode]) {
                ans = true;
                return;
            } else if(!isVisited[node]) {
                q.push(node);
                isVisited[node] = true;
                parent[node] = frontNode;
            }
        }
    }
}

void dfs(int stNode, int parent, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& isVisited, bool& ans) {
    if(!isVisited[stNode]) {
         isVisited[stNode] = true;
    
        for(int node: adjList[stNode]) {
            if(!isVisited[node]) {
                dfs(node, stNode, adjList, isVisited, ans);
            } else if(node != parent) {
                ans = true;
                return;
            }
        }
    }
}

bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    //create adjacency list
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    
    //create visited map and initialize false for all nodes
    unordered_map<int, bool> isVisited;
    for(int i = 0; i < V; i++) {
        isVisited[i] = false;
    }
    
    bool ans = false;
    
    //bfs or, dfs
    for(int i = 0; i < V; i++) {
        if(!isVisited[i]) {
            //bfs(i, adjList, isVisited, ans);
            dfs(i, -1, adjList, isVisited, ans);
        }
    }
    return ans;
}

int main() {
    int v = 4, e = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << isCycle(v, edges) << "\n";
    return 0;
}