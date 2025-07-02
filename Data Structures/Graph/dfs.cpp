#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool>& isVisited, vector<vector<int>>& adj, vector<int>& ans) {
    //1.Print the node.
    //2. For it's adjacent nodes go to 1 level deeper if !isVisited
    ans.push_back(node); //ans store
    isVisited[node] = true; //mark visited
    
    //recursive call for all connected node
    for(auto i: adj[node]) {
        if(!isVisited[i]) {
            dfs(i, isVisited, adj, ans);
        }
    }
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