#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    int arrNo, idx;
    
    Node(int data, int arrNo, int idx) {
        this->data = data;
        this->arrNo = arrNo;
        this->idx = idx;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
    // code here
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    //1. insert all the array's first element to the minHeap
    for(int i = 0; i < k; i++) {
        Node* temp = new Node(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    //2.
    while(minHeap.size() > 0) {
        Node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        //enter next element of the array from which the element has been pushed to ans
        int arrNo = temp->arrNo;
        int nextIdx = temp->idx + 1;

        if(nextIdx < arr[arrNo].size()) {
            Node* newNode = new Node(arr[arrNo][nextIdx], arrNo, nextIdx);
            minHeap.push(newNode);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {5, 9, 34}, {8, 11, 37}};
    vector<int> ans = mergeKArrays(arr, 3);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}