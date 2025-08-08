#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void buildLvlOrder(TreeNode* root) {
    queue<TreeNode*> q;
    cout << "Enter data for root node: ";
    int root_data;
    cin >> root_data;
    root = new TreeNode(root_data);
    q.push(root);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << "Enter data for the left node of " << temp->data << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new TreeNode(l_data);
            q.push(temp->left);
        }

        cout << "Enter data for the right node of " << temp->data << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->left = new TreeNode(r_data);
            q.push(temp->right);
        }
    }
}

TreeNode* createParentMap(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
    TreeNode* result = NULL;

    queue<TreeNode*> q;
    q.push(root);
    nodeToParent[root] = NULL; //as root has no parent

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if(temp->data == start) result = temp; //target node finding

        //mapping children to their parent
        if(temp->left) {
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right) {
            nodeToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }

    return result;
}

void infectTree(TreeNode* startNode, int& time, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;

    q.push(startNode);
    visited[startNode] = true;

    while(!q.empty()) {
        int size = q.size();
        bool flag = false; 
        //using loop as we want to infect all the neighbouring nodes for remaining nodes in queue(they were infected before
        //and as each infected node will infect their own neighbouring nodes)
        for(int i =0; i < size; i++) { //process neighbouring nodes
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left && !visited[temp->left]) {//left
                flag = true;
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if(temp->right && !visited[temp->right]) {//right
                flag = true;
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if(nodeToParent[temp] && !visited[nodeToParent[temp]]) {//parent
                flag = true;
                q.push(nodeToParent[temp]);
                visited[nodeToParent[temp]] = true;
            }
        }

        if(flag) time++; //as that means new element is pushed to queue(neighbouring node exists and infected)
    }
}

int amountOfTime(TreeNode* root, int start) {
    //Step 1: create Node and parent mapping
    //Step 2: find target Node
    //Step 3: Burn the tree

    int time = 0;
    unordered_map<TreeNode* , TreeNode*> nodeToParent;
    TreeNode* startNode = createParentMap(root, start, nodeToParent);
    infectTree(startNode, time, nodeToParent);

    return time;
}

int main() {
    return 0;
}