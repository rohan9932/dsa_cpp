#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int row, col;
    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    int minimum = INT_MAX, maximum = INT_MIN;
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    //1. enter first elements in the heap
    for(int i = 0; i < k; i++) {
        int element = nums[i][0];
        maximum = max(maximum, element);
        minHeap.push(new Node(element, i, 0));
    }

    int st = minHeap.top()->data, end = maximum;

    while(!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();
        minimum = temp->data;

        if(maximum - minimum < end - st) { //lower range found
            st = minimum;
            end = maximum;
        }

        if(temp->col + 1 < nums[temp->row].size()) {
            maximum = max(maximum, nums[temp->row][temp->col+1]);
            minHeap.push(new Node(nums[temp->row][temp->col+1], temp->row, temp->col+1));
        } else break;
    }
    
    return {st, end};
}

int main() {
    return 0;
}