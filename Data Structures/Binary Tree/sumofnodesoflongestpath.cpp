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

void buildLvlOrder(Node*& root) {
    queue<Node*> q;
    cout << "Enter data for root node: ";
    int root_data;
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

void helper(Node* root, int sum, int& maxSum, int len, int& maxLen) {
    //base case
    if(root == NULL) {//possible end path
        if(len > maxLen) {//max path
            maxLen = len;
            maxSum = sum; //update to the sum as it's the highest length
        } else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;
    helper(root->left, sum, maxSum, len+1, maxLen);
    helper(root->right, sum, maxSum, len+1, maxLen);
}

int sumOfLongRootToLeafPath(Node *root) {
    // code here
    int len = 0, maxLen = 0;
    int sum = 0, maxSum = 0;
    helper(root, sum, maxSum, len, maxLen);
    return maxSum;
}

int main() {
    return 0;
}