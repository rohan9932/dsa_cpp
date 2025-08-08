#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    unordered_map<int, list<pair<int, int>>> adjList;
public:
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
    }

    void printAdjList() {
        for(auto i: adjList) {
            cout << i.first << " -> ";
            for(auto j: i.second) {
                cout << "(" << j.first << ", " << j.second << ")" << " ";
            }
            cout << "\n";
        }
    }

    void dfs(int node, unordered_map<int, list<pair<int, int>>>& adjList, vector<bool>& isVisited, stack<int>& topoS) {
        isVisited[node] = true;

        for(auto neighbour: adjList[node]) {
            if(!isVisited[neighbour.first]) {
                dfs(neighbour.first, adjList, isVisited, topoS);
            }
        }
        
        topoS.push(node);
    }

    //topo sort
    vector<int> topoSort() {  
        vector<int> ans;
        vector<bool> isVisited(adjList.size(), false);

        stack<int> topoS;
        for(int i = 0; i < adjList.size(); i++) {
            if(!isVisited[i]) {
                dfs(i, adjList, isVisited, topoS);
            }
        }

        while(!topoS.empty()) {
            ans.push_back(topoS.top());
            topoS.pop();
        }

        return ans;
    }

    //Shortest Path
    vector<int> shortestPathfromSrc(int src, vector<int>& topoSort) {
        //1. create an dist array and initialize all the dist value to -1
        vector<int> distArrfromSrc(adjList.size(), -1);
        //2. set src node dist to 0
        distArrfromSrc[src] = 0;
        //3. Now traverse topoSort and for it's neighbours update shortest dist if rechable from src
        for(int i = 0; i < topoSort.size(); i++) {
            int node = topoSort[i];
            if(distArrfromSrc[node] != -1) {
                //it's accessible from src
                //neighbour node shortest dist set
                for(auto neighbour: adjList[node]) {
                    int neighbourNode = neighbour.first;
                    int neighbourWeight = neighbour.second;
                    int dist = distArrfromSrc[node] + neighbourWeight;

                    //We need to change if the dist to that neighbour node is -1(initialize dist) or if there
                    //was previously distance stored but we got even lower distance
                    if(distArrfromSrc[neighbourNode] == -1 || (dist < distArrfromSrc[neighbourNode])) {
                        distArrfromSrc[neighbourNode] = dist;
                    }
                }
            }
        }
        return distArrfromSrc;
    }
};


int main() {
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    //take topological sort of the graph
    vector<int> topoS = g.topoSort();
    for(int i = 0; i < topoS.size(); i++) {
        cout << topoS[i] << " ";
    }
    cout << "\n";

    vector<int> shortestPath = g.shortestPathfromSrc(0, topoS);
    for(int i = 0; i < shortestPath.size(); i++) {
        cout << shortestPath[i] << " ";
    }
    return 0;
}