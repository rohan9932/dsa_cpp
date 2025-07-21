#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;
    int vertices;

    DisjointSet(int V) {
        parent.resize(V);
        rank.resize(V);
        this->vertices = V;
    }

    void makeSet() {
        for(int i = 0; i < vertices; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int node) { //recursively find root parent
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]); //path compression 
    }

    void unionSet(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);

        if(rank[parU] < rank[parV]) {
            parent[parU] = parV;
        } else if(rank[parV] < rank[parU]) {
            parent[parV] = parU;
        } else {
            parent[parV] = parU;
            rank[parU]++;
        }
    }
};

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2]; //ascending order
}

int minimumSpanningTree(vector<vector<int>>& edges, int V) {
    int ans = 0;
    sort(edges.begin(), edges.end(), cmp);

    DisjointSet set(V);
    set.makeSet();

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if(set.findParent(u) != set.findParent(v)) { // !in same component or !inMst
            ans += weight;
            set.unionSet(u, v);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    cout << minimumSpanningTree(edges, 3) << "\n";
    return 0;
}