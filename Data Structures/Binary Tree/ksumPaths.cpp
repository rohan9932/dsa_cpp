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
    root = new Node(root->data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data for the left node of " << temp->data << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new Node(l_data);
            q.push(temp->left);
        } 

        cout << "Enter data for the right node of " << temp->data << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->right = new Node(r_data);
            q.push(temp->right);
        }
    }
}

void helper(Node* root, int k, int& count, vector<int> path) {
    //base case
    if(root == NULL) return;

    path.push_back(root->data);

    //left and right call
    helper(root->left, k, count, path);
    helper(root->right, k, count, path);

    //check if k sum exists
    int sum = 0;
    for(int i = path.size()-1; i >= 0; i--) {
        sum += path[i];
        if(sum == k) count++;
    }

    //don't need to backtrack as we are just passing path by value
}

int sumK(Node* root, int k) {
    vector<int> path;
    int count = 0;
    helper(root, k, count, path);
    return count;
}

//SumK in O(n) time complexity

void helper2(Node* root, int k, int currSum, int& count, unordered_map<int, int>& prefix_sum) {
    if(root == NULL) return;

    currSum += root->data; //updating currSum

    if(prefix_sum.find(currSum - k) != prefix_sum.end()) { //checking is any viable path exists
        count += prefix_sum[currSum - k];
    }

    prefix_sum[currSum]++; //inputting the currSum in the hashmap

    helper2(root->left, k, currSum, count, prefix_sum);
    helper2(root->right, k, currSum, count, prefix_sum);

    //backtracking step
    prefix_sum[currSum]--;
}

int sumK(Node* root, int k) {
    int count = 0;
    int currSum = 0;
    unordered_map<int, int> prefix_sum;
    prefix_sum[0] = 1;
    helper2(root, k, currSum, count, prefix_sum);
    return count;
}

int main() {
    return 0;
}