#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
    int k = lists.size();
    if(k == 0) return NULL;

    //1.Insert heads to minHeap
    for(int i = 0; i < k; i++) {
        if(lists[i] != NULL) {
            minHeap.push(lists[i]);
        }
    }

    ListNode* head = NULL; //Empty answer LL
    ListNode* tail = NULL;

    //2. 
    while(!minHeap.empty()) {
        ListNode* temp = minHeap.top();
        minHeap.pop();

        if(temp->next != NULL) {
            minHeap.push(temp->next);
        }        

        if(head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp; //inserting from tail
            tail = temp; //moving tail to end
        }
    }

    return head;
}

int main() {
    return 0;
}