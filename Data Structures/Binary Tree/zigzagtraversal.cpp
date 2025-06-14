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

void buildfromLvlOrder(Node* root) {
    queue<Node*> q;
    int data;
    cout << "Enter root data: ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->left << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new Node(l_data);
            q.push(temp->left);
        }

        cout << "Enter data for the right node of " << temp->right << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->right = new Node(r_data);
            q.push(temp->right);
        }
    }
}

vector<int> zigZagTraversal(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> temp(size);
        //Level Process
        for(int i = 0; i < size; i++) {
            Node* frontNode = q.front();
            q.pop();

            int idx = leftToRight ? i : size-1-i;
            temp[idx] = frontNode->data;

            if(frontNode->left) {
                q.push(frontNode->left);
            }
            if(frontNode->right) {
                q.push(frontNode->right);
            }
        }
        
        //changing direction
        leftToRight = !leftToRight;

        //inserting elements in level to the ans
        for(auto i: temp) {
            ans.push_back(i);
        }
    }

    return ans;
}

//Modified code
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    bool isReversed = false;

    while(!q.empty()) {
        //handle each level
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        //check if need to go right -> left
        if(isReversed) reverse(level.begin(), level.end());
        ans.push_back(level);
        isReversed = !isReversed; //change direction
    }

    return ans;
}

int main() {

    return 0;
}