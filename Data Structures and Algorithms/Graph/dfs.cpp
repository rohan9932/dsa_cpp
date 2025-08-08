#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool>& isVisited, vector<vector<int>>& adj, vector<int>& ans) {
    /*
        take action on vertex after entering the vertex
        here we are marking the node visited as true
    */
    ans.push_back(node);
    isVisited[node] = true;
    
    for(auto i: adj[node]) {
        /*
            Take action on child before entering the child node
            here it's checking is the node visited or not
        */
        if(!isVisited[i]) {
            dfs(i, isVisited, adj, ans);
        }
        /*
            Take action on child after exiting child node
        */
    }
    /*
        Take action on vertex before exiting the vertex
    */
}

vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    vector<int> ans;
    unordered_map<int, bool> isVisited;
    for(int i = 0; i < adj.size(); i++) { //initializing !visited => all nodes
        isVisited[i] = false;
    }

    dfs(0, isVisited, adj, ans);

    //if disconnected graph then
    /*
    for(int i = 0; i < adj.size(); i++) {
        if(!isVisited[i]) {
            dfs(i, isVisited, adj, ans);
        }
    }
    */
    
    return ans;
}

int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    vector<int> ans = dfs(adj);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}