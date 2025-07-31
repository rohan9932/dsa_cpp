#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    //1. dist vector to keep track of shortest dist
    vector<int> dist(V, 1e8); //initializing with large number
    dist[src] = 0;
    
    //2. dist update (running n-1 times)
    for(int i = 0; i < V-1; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != 1e8 && (dist[u] + wt < dist[v])) { //condition cheack
                dist[v] = dist[u] + wt;
            }
        }
    }
    
    //check negative weight
    for(int k = 0; k < edges.size(); k++) {
        int u = edges[k][0];
        int v = edges[k][1];
        int wt = edges[k][2];
        
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]) { //condition cheack
            return {-1}; //negative cycle present
        }
    }
    
    return dist;
}

int main() {

return 0;
}