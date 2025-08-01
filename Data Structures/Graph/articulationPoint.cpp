#include<bits/stdc++.h>
using namespace std;

void dfs(int currNode, vector<int> adj[], vector<bool>& isVisited, vector<int>& parent, vector<int>& disconnectedChildren, vector<int>& dt, vector<int>& lowestDt, set<int>& articulationPoint, int& time) {
    isVisited[currNode] = true;
    //update Discovery Time
    dt[currNode] = lowestDt[currNode] = ++time;
    for(auto neighbour: adj[currNode]) {
        //No backedge case
        if(!isVisited[neighbour]) {
            //set parent and dfs
            parent[neighbour] = currNode;
            dfs(neighbour, adj, isVisited, parent, disconnectedChildren, dt, lowestDt, articulationPoint, time);
            //update low after returning from child
            lowestDt[currNode] = min(lowestDt[currNode], lowestDt[neighbour]);
            //articulation point 2nd condition check
            if(parent[currNode] != -1 && (dt[currNode] <= lowestDt[neighbour])) {
                articulationPoint.insert(currNode);
            }
            //update disconnected children count
            disconnectedChildren[currNode]++;
        } 
        //back edge case
        else if(neighbour != parent[currNode]) {
            lowestDt[currNode] = min(lowestDt[currNode], dt[neighbour]);
        }
    }
    //before returning from the vertex check 1st condition of articulation point
    if(parent[currNode] == -1 && disconnectedChildren[currNode] > 1) {
        articulationPoint.insert(currNode);
    }
}

vector<int> articulationPoints(int V, vector<int> adj[]) {
    //initialize needed DS
    vector<bool> isVisited(V, false);
    vector<int> parent(V, -1);
    vector<int> dt(V);
    vector<int> lowestDt(V);
    vector<int> children(V, 0);
    set<int> articulationPoint;
    
    int time = 0;
    
    for(int i = 0; i < V; i++) {
        if(!isVisited[i]) {
            dfs(i, adj, isVisited, parent, children, dt, lowestDt, articulationPoint, time);
        }
    }
    
    vector<int> ans(articulationPoint.begin(), articulationPoint.end());
    
    return (ans.size() > 0) ? ans: vector<int>{-1};
}

int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3, 4};
    adj[3] = {2, 4};
    adj[4] = {2, 3};

    vector<int> ans = articulationPoints(V, adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}