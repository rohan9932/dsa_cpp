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


//------------------BFS-----------------
bool isCyclicBFS(int V, vector<vector<int>> &edges) {
    //make adjList
    unordered_map<int , list<int>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    //Calculate inDegree for each node
    vector<int> inDegree(V);
    for(auto list: adjList) {
        for(auto node: list.second) {
            inDegree[node]++;
        }
    }
    //BFS
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0; //take a counter to make count of nodes visited
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        //increase node count
        cnt++;
        
        for(auto node: adjList[frontNode]) {
            inDegree[node]--;
            if(inDegree[node] == 0) {
                q.push(node);
            }
        }
    }
    //cnt of nodes visited == V means it's a Directed Acyclic Graph(Valid Topological Sort)
    return (cnt == V)? false: true;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}};
    cout << isCyclicBFS(4, edges) << "\n";
    return 0;
}