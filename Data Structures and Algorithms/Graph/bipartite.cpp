#include<bits/stdc++.h>
using namespace std;

/*
    1. Start coloring with 0 and 1 using DFS
    2. If for any node it isn't parent but visiited and is in same color -> not bipartite
*/

void parentNode(int vertex, vector<vector<int>>& graph, vector<bool>& isVisited, vector<int>& parent) {
    isVisited[vertex] = true;

    for(auto neighbour: graph[vertex]) {
        if(!isVisited[neighbour]) {
            parent[neighbour] = vertex;
            parentNode(neighbour, graph, isVisited, parent);
        }
    }
}

void dfs(int vertex, vector<vector<int>>& graph, vector<bool>& isVisited, vector<int>& parent, vector<int>& colorArr, int color, bool& isBipartite) {
    isVisited[vertex] = true;
    colorArr[vertex] = color;
    for(auto neighbour: graph[vertex]) {
        int nextColor = (color == 1) ? 0: 1;
        if(isVisited[neighbour] && parent[vertex] != neighbour && colorArr[neighbour] == color) {
            isBipartite = false;
        }
        else if(!isVisited[neighbour]) {
            dfs(neighbour, graph, isVisited, parent, colorArr, nextColor, isBipartite);
        }
    }
}


bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> isVisited(n, false);
    vector<int> parent(n, -1);

    //parent nodes
    for(int i = 0; i < n; i++) {
        if(!isVisited[i]) {
            parentNode(0, graph, isVisited, parent);
        }
    }

    //refill all the vector value to false for future usage
    fill(isVisited.begin(), isVisited.end(), false);

    //check bipartite
    bool ans = true;
    vector<int> colorArr(n, -1);
    for(int i = 0; i < n; i++) {
        if(!isVisited[i]) {
            dfs(0, graph, isVisited, parent, colorArr, 0, ans);
        }
    }

    return ans;
}


int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    cout << isBipartite(graph) << endl;
    return 0;
}