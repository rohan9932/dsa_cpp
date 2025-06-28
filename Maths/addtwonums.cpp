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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp = new ListNode(0); 
    ListNode* curr = temp;
    int carry = 0;

    //we are using basic maths add
    // 108 + 19 = 
    // first we do 9 + 8 = 17 where 7 is the carry
    //then we add the carry to next left digits sum and continue
    while(l1 != NULL || l2 != NULL) {
        int sum = carry;
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        int digval = sum % 10;
        carry = sum/10;

        curr->next = new ListNode(digval);
        curr = curr->next; //move forward
    }

    if(carry != 0) {
        curr->next = new ListNode(carry);
    }
    
    return temp->next;
} 

int main() {
    return 0;
}