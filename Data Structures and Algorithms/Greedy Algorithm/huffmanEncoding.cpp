#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

class Comparator {
  public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; //min Heap
    }
};


void preorder(Node* root, string encodedStr, vector<string>& ans) {
    //base case->leaf node
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(encodedStr);
        return;
    }
    
    preorder(root->left, encodedStr+'0', ans);
    preorder(root->right, encodedStr+'1', ans);
}

vector<string> huffmanCodes(string S, vector<int> f, int N) {
    priority_queue<Node* , vector<Node*>, Comparator> pq;
    for(int i = 0; i < f.size(); i++) {
        Node* temp = new Node(f[i]);
        pq.push(temp);
    }
    
    //make tree
    while(pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        
        Node* right = pq.top();
        pq.pop();
        
        
        Node* newNode = new Node(left->data + right->data);
        newNode->left = left;
        newNode->right = right;
        
        pq.push(newNode);
    }
    
    Node* root = pq.top();
    vector<string> ans;
    string encodedStr = "";
    preorder(root, encodedStr, ans);
    
    return ans;
}

int main() {

    return 0;
}