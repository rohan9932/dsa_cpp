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

int main() {
    return 0;
}