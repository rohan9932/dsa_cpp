#include<bits/stdc++.h>
using namespace std;

//------------DFS-----------------
void dfs(int stNode, unordered_map<int, list<int>>& adjList, vector<bool>& isVisited, stack<int>& topologicalStack) {
    isVisited[stNode] = true;
    
    for(auto node: adjList[stNode]) {
        if(!isVisited[node]) {
            dfs(node, adjList, isVisited, topologicalStack);
        }
    }
    
    topologicalStack.push(stNode);
}

vector<int> topoSort(int V, vector<vector<int>>& edges) { 
    // code here
    //DFS and while returning from a recursion stack store the node in stack
    //Then just push the stack values by which we will get topological sort

    vector<int> ans;
    //making adjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }
    
    //replacing map with vector where each indices refer to nodes and values refer to it's state
    vector<bool> isVisited(V, false);
    
    stack<int> topologicalStack;
    
    for(int i = 0; i < V; i++) {
        if(!isVisited[i]) {
            dfs(i, adjList, isVisited, topologicalStack);
        }
    }
    
    while(!topologicalStack.empty()) {
        ans.push_back(topologicalStack.top());
        topologicalStack.pop();
    }
    return ans;
}


//------------BFS-----------------
vector<int> topoSortBFS(int V, vector<vector<int>>& edges) { 
    // code here
    vector<int> ans;
    //making adjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }

    //find all indegree
    vector<int> inDegree(V);
    for(auto list: adjList) {
        for(auto node: list.second) {
            inDegree[node]++;
        }
    }
    
    queue<int> topologicalSorted;
    
    //push 0 indgree nodes to queue
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) {
            topologicalSorted.push(i);
        }
    }
    
    //BFS and putting nodes when weight becomes 0
    while(!topologicalSorted.empty()) {
        int frontNode = topologicalSorted.front();
        topologicalSorted.pop();
        
        ans.push_back(frontNode); //push to ans
        
        for(auto node: adjList[frontNode]) {
            inDegree[node]--;
            if(inDegree[node] == 0) {
                topologicalSorted.push(node);
            }
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5,2}};
    int V = 6;
    
    vector<int> ans = topoSort(V, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}