#include<bits/stdc++.h>
using namespace std;
template <typename T>

class Graph {
public:
    unordered_map<T, list<T>> adj;
    
    void addEdgeAdjList(T u, T v, bool direction) {
        //direction -> 0 => undirected
        //direction -> 1 => directed

        //create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0) {
            adj[v].push_back(u);
        }
    }

    void addEdgeAdjMat(T u, T v, vector<vector<T>>& adjMat, bool direction) { //O(1)
        //0 => Undirected
        //1 => Directed
        adjMat[u][v] = 1;
        if(direction == 0) adjMat[v][u] = 1;
    }

    void printAdjList() {
        for(auto i: adj) {
            cout << i.first << "-> ";
            for(auto j: i.second) {
                cout << j << ", ";
            }
            cout << "\n";
        }
    }   
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "\n";

    int m;
    cout << "Enter the number of the edges: ";
    cin >> m;
    cout << "\n";

    Graph<int> g;

    // for(int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     //creating an undirected graph
    //     g.addEdgeAdjList(u, v, 0);
    // }

    vector<vector<int>> adjMat(n, vector<int>(m, 0));
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >>  v;
        g.addEdgeAdjMat(u, v, adjMat, 1);
    }

    for(int i = 0; i < adjMat.size(); i++) { //O(N*M)
        for(int j = 0; j < adjMat[i].size(); j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << "\n";
    }

    // //printGraph
    // g.printAdjList();

    return 0;
}