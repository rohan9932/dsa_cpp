#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> edges) {
    int ans = 0;
    //create adjList
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    //first create the data structures needed
    vector<int> key(V, INT_MAX); //for tracking least weight for that node
    vector<bool> isMST(V, false);

    //initialization 
    key[0] = 0;

    for(int i = 0; i < V; i++) {
        int min = INT_MAX;
        int u;
        //find the min value
        for(int j = 0; j < V; j++) {
            if(isMST[j] == false && key[j] < min) {
                u = j;
                min = key[j];
            }
        }

        //mark the curr node true in mst
        isMST[u] = true;

        //Check adj Nodes
        for(auto neighbour: adjList[u]) {
            int v = neighbour.first;
            int weight = neighbour.second;
            if(isMST[v] == false && weight < key[v]) {
                key[v] = weight; //update least weight
            }
        }
    }

    for(int i = 0; i < key.size(); i++) {
        ans += key[i];
    }
    return ans;
}

int spanningTreewithMinHeap(int V, vector<vector<int>> edges) {
    int ans = 0;
    //create adjList
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    //data sturctures needed
    vector<int> key(V, INT_MAX); 
    vector<bool> isMST(V, false);

    //heap for tracking minimum value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    key[0] = 0;
    minHeap.push({0, 0}); //{weight, node}

    while(!minHeap.empty()) {
        auto [minWeight, u] = minHeap.top();
        minHeap.pop();

        if(isMST[u]) continue; //ignore if already in MST

        isMST[u] = true;
        ans += key[u];

        for(auto [node, weight] : adjList[u]) {
            if(isMST[node] == false && weight < key[node]) {
                key[node] = weight; //update least weight
                minHeap.push({key[node], node});
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    cout << spanningTreewithMinHeap(3, edges) << "\n";
    return 0;
}