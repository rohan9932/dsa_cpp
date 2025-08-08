#include <bits/stdc++.h>
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

Node* insertToBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    //recursive call
    if(data < root->data) {
        root->left = insertToBST(root->left, data);
    } else {
        root->right = insertToBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;
    if(data != -1) {
        root = insertToBST(root, data);
        cin >> data;
    }
}

//Approach 1
void makeInorder(Node* root, vector<int>& inorder) {
    if(root == NULL) return;
    
    makeInorder(root->left, inorder);
    inorder.push_back(root->data);
    makeInorder(root->right, inorder);
}

vector<int> mergeArr(vector<int> arr1, vector<int> arr2) {
    vector<int> ans;
    
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        }
        else { 
            ans.push_back(arr2[j]);
            j++;
        }
    }
    
    while(i < arr1.size()) {
        ans.push_back(arr1[i]);
        i++;
    }
    
    while(j < arr2.size()) {
        ans.push_back(arr2[j]);
        j++;
    }
    
    return ans;
}

Node* inorderToBST(vector<int>& arr, int st, int end) {
    if(st > end) return NULL;
    
    int mid = st + (end-st)/2;
    Node* root = new Node(arr[mid]);
    root->left = inorderToBST(arr, st, mid-1);
    root->right = inorderToBST(arr, mid+1, end);
    
    return root;
}

vector<int> merge(Node *root1, Node *root2) {
    // Your code here
    //1. make inorder vec of the 2 BST
    vector<int> tree1Inorder, tree2Inorder;
    makeInorder(root1, tree1Inorder);
    makeInorder(root2, tree2Inorder);
    
    //2. Merge the BST arrays
    vector<int> mergedArr = mergeArr(tree1Inorder, tree2Inorder);
    Node* root = inorderToBST(mergedArr, 0, mergedArr.size()-1);
    
    //3. trasform the merged array to BST
    vector<int> ans;
    makeInorder(root, ans);
    
    return ans;
}

//Approach 2
void convertIntoDLL(Node* root, Node*& head) { //TC: O(m+n) SC: O(h1 + h2)
    //base case
    if(root == NULL) return;
    //recursive call
    convertIntoDLL(root->right, head);
    root->right = head;
    if(root->left != NULL) { //if right subtree is null
        head->left = root;
    }
    head = root;
    convertIntoDLL(root->left, head);
} 

Node* mergedLL(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1; //pushing after tail
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if(head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2; //pushing after tail
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL) {
        tail->right = head1; //pushing after tail
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL) {
        tail->right = head2; //pushing after tail
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* sortedLLToBST(Node*& head, int n) {
    //base case
    if(n <= 0 || head == NULL) return NULL;

    Node* leftTree = sortedLLToBST(head, n/2);
    Node* root = head;
    root->left = leftTree;

    head = head->right;
    root->right = sortedLLToBST(head, n-n/2-1); //rightTree

    return root;
}

vector<int> merge2(Node *root1, Node *root2) {
    //1. converting trees in DLL
    Node* head1 = NULL;
    Node* head2 = NULL;
    convertIntoDLL(root1, head1);
    head1->left = NULL;
    convertIntoDLL(root2, head2);
    head2->left = NULL;
    //2. merging 2 sorted LL
    Node* mergedHead = mergedLL(head1, head2);
    //3. LL to BST
    Node* root = sortedLLToBST(mergedHead, countNodes(mergedHead));

    vector<int> ans;
    makeInorder(root, ans);

    return ans;
}

int main() {
    return 0;
}