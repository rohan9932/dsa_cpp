#include<bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<vector<int>>& adj, unordered_map<int, bool>& isVisited, int node, vector<int>& ans) {
    //1.Take the start node and push it to queue. Change it to visited.
    //2. Then start traversing the queue till q.empty(). pick up the frontNode
    //3. push it to queue and push it's adjacent and univisited nodes to queue. if a node is pushed
    //   make it visited.
    queue<int> q; 
    q.push(node);
    isVisited[node] = true;
    
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);
        
        for(auto i: adj[frontNode]) {
            if(!isVisited[i]) {
                q.push(i);
                isVisited[i] = true;
            }
        }
    }
}

// Function to return Breadth First Traversal of given graph.
vector<int> bfs(vector<vector<int>> &adj) { //O(V+E)
    // Code here
    vector<int> ans;
    
    int nodes = adj.size();
    
    unordered_map<int, bool> isVisited;
    for(int i = 0; i < nodes; i++) { //initializing !visited => all nodes
        isVisited[i] = false;
    }

    for(int i = 0; i < nodes; i++) { //for disconnected graph edge case(to cover all nodes)
        if(!isVisited[i]) {
            bfsTraversal(adj, isVisited, i, ans);
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    vector<int> ans = bfs(adj);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}