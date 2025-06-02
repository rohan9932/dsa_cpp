#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void buildLvlOrder(Node* root) {
    queue<Node*> q;
    int root_data;
    cout << "Enter data for root node: ";
    cin >> root_data;
    root = new Node(root_data);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->data << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new Node(l_data);
        }

        cout << "Enter data for right node of " << temp->right << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->right = new Node(r_data);
        }
    }
}

vector<int> diagonal(Node *root) {
    // code here
    vector<int> ans;
    map<int, vector<int>> nodes;
    queue<pair<Node*, int>> q;

    //base case
    if(root == NULL) return ans;
    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> front = q.front();
        q.pop();
        
        Node* frontNode = front.first;
        int diag_dist = front.second;
        
        //traverse through the diagonal distance
        while(frontNode) { //because the left subtree should be taken first
            nodes[diag_dist].push_back(frontNode->data);
            
            if(frontNode->left) {
                q.push(make_pair(frontNode->left, diag_dist+1));
            }
            
            frontNode = frontNode->right;
        }
    }

    for(auto& i: nodes) {
        for(auto j: i.second) {
            ans.push_back(j);
        }
    }

    return ans;
}

int main() {
    return 0;
}