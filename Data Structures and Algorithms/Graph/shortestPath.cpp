#include<bits/stdc++.h>
using namespace std;

//-------------------UNDIRECTED GRAPH------------------
void bfs(int stNode, vector<vector<int>>& adj, vector<bool>& isVisited, vector<int>& parentNode) {
    queue<int> q;
    q.push(stNode);
    isVisited[stNode] = true;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto node: adj[frontNode]) {
            if(!isVisited[node]) {
                q.push(node);
                isVisited[node] = true;
                parentNode[node] = frontNode;
            }
        }
    }
}

int shortestPathDist(int src, int tar, vector<int>& parentNode) {
    int dist = 0;
    int currNode = tar;
    //go to parent till src and figure out shortest Distance
    while(currNode != src) {
        if(parentNode[currNode] == -1) return -1;
        currNode = parentNode[currNode]; 
        dist++;
    }
    return dist;
}

vector<int> shortestPathUndir(vector<vector<int>>& adj, int src) {
    vector<int> ans;
    //visited map and setting them false for each node first
    vector<bool>isVisited(adj.size(), false);

    //create parent mapping using bfs 
    //initializing all node dist to -1 then we will cnt distance and change them
    vector<int> parentNode(adj.size(), -1);
    //track parent of all the nodes of the component where src node is
    bfs(src, adj, isVisited, parentNode);

    //we know bfs travels in shortest path
    //so we can just figure out ans from bactracking from the target node -> src node
    //Now we will just take the shortest dist from all the nodes to src nodes and store them to ans
    for(int i = 0; i < adj.size(); i++) {
        int shortestDist = shortestPathDist(src, i, parentNode);
        ans.push_back(shortestDist);
    }

    return ans;
}

int main() {
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    int src = 0;

    vector<int> ans = shortestPathUndir(adj, src);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}