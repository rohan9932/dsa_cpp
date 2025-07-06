#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> adjMat;

    Graph() {
        adjMat = vector<vector<int>>(100, vector<int>(100, 0));
    }

    void addAdjEdgeList(int u, int v, bool isDirected) {
        adjList[u].push_back(v);
        if(!isDirected) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for(auto it: adjList) {
            cout << it.first << " -> ";
            for(auto j: it.second) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    void addEdgeAdjMat(int u, int v, bool isDirected) {
        adjMat[u][v] = 1;
        if(!isDirected) {
            adjMat[v][u] = 1;
        }
    }

    void printAdjMat(int v) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                cout << adjMat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void bfsHelper(int node, unordered_map<int, bool>& isVisited, vector<int>& ans) {
        queue<int> q;
        q.push(node);
        isVisited[node] = true;

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto i: adjList[frontNode]) {
                if(!isVisited[i]) {
                    q.push(i);
                    isVisited[i] = true;
                }
            }
        }
    }

    vector<int> bfs(int stNode) {
        vector<int> ans;
        unordered_map<int, bool> isVisited;
        for(auto it: adjList) {
            isVisited[it.first] = false;
        }

        bfsHelper(stNode, isVisited, ans);
        return ans;
    }

    void dfsHelper(int node, unordered_map<int, bool>& isVisited, vector<int>& ans) {
        if(!isVisited[node]) {
            ans.push_back(node);
            isVisited[node] = true;
        }

        for(auto i: adjList[node]) {
            if(!isVisited[i]) {
                dfsHelper(i, isVisited, ans);
            }
        }
    }

    vector<int> dfs(int stNode) {
        vector<int> ans;
        unordered_map<int, bool> isVisited;
        for(auto it: adjList) {
            isVisited[it.first] = false;
        }

        dfsHelper(stNode, isVisited, ans);

        return ans;
    }
};

int main() {
    Graph g;

    //adj list
    vector<pair<int,int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {1, 5}};

    for(auto i: edges) {
        g.addAdjEdgeList(i.first, i.second, false);
        g.addEdgeAdjMat(i.first, i.second, false);
    }


    g.printAdjList();
    g.printAdjMat(5);

    vector<int> bfs = g.bfs(0);
    for(auto val: bfs) cout << val << " ";
    cout << "\n";

    vector<int> dfs = g.dfs(0);
    for(auto val: dfs) cout << val << " ";
    cout << "\n";

    cout << "\n";
}