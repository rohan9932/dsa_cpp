#include<bits/stdc++.h>
using namespace std;

void dfsStorefinishTime(int node, vector<vector<int>> adj, vector<bool>& isVisited, stack<int>& s) {
    isVisited[node] = true;

    for(auto neighbour: adj[node]) {
        if(!isVisited[neighbour]) {
            dfsStorefinishTime(neighbour, adj, isVisited, s);
        }
    }
    s.push(node);
}

void dfs(int node, vector<vector<int>>& transpose, vector<bool>& isVisited) {
    isVisited[node] = true;

    for(auto neighbour: transpose[node]) {
        if(!isVisited[neighbour]) {
            dfs(neighbour, transpose, isVisited);
        }
    }
}

int kosaraju(vector<vector<int>> &adj) {
    int sccCount = 0;

    //1.finish time in descending order(stack)
    int V = adj.size(); //vertices
    vector<bool> isVisited(V, false);
    stack<int> s;
    for(int i = 0; i < V; i++) {
        if(!isVisited[i]) {
            dfsStorefinishTime(i, adj, isVisited, s);
        }
    }

    //2.transpose graph
    vector<vector<int>> transpose(V); //need to initialize first
    for(int i = 0; i < V; i++) {
        isVisited[i] = false; //reinitializing isVisited for future use
        for(auto neighbour: adj[i]) {
            transpose[neighbour].push_back(i);
        }
    }

    //3.dfs the transpose graph
    while(!s.empty()) {
        int temp = s.top();
        s.pop();

        if(!isVisited[temp]) {
            dfs(temp, transpose, isVisited);
            sccCount++;
        }
    }

    return sccCount;
}

int main() {
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};
    cout << kosaraju(adj) << endl;
    return 0;
}