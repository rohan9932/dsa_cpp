#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    //create adjList
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adjList[u].push_back({v, weight}); //in adjList {node, weight} pair
        adjList[v].push_back({u, weight});
    }

    vector<int> dist(V, INT_MAX); //dist tracking array(initialized with infinity at first)
    set<pair<int, int>> s; //to keep track of the shortest dist from the curr node

    //initialize for src node
    dist[src] = 0;
    s.insert({0, src}); //in set {dist, node} pair

    while(!s.empty()) {
        //top record
        auto top = *(s.begin());
        int nodeDist = top.first;
        int topNode = top.second;

        //remove top
        s.erase(s.begin());

        //traverse on neighbours (relaxation step)
        for(auto neighbour: adjList[topNode]) { //O(ElogV)
            int nextDist = nodeDist + neighbour.second;
            if(nextDist < dist[neighbour.first]) {
                //check if a record with curr node is available
                auto record = s.find({dist[neighbour.first], neighbour.first});
                //if record found erase it
                if(record != s.end()) {
                    s.erase(record);
                }

                //update dist
                dist[neighbour.first] = nextDist;
                //push record to set
                s.insert({nextDist, neighbour.first});
            }  
        }
    }
    return dist;
}

int main() {
    int v = 3, src = 2;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};

    vector<int> shortestDist = dijkstra(v, edges, src);
    for(int i = 0; i < shortestDist.size(); i++) {
        cout << shortestDist[i] << " ";
    }
    cout << "\n";
    return 0;
}