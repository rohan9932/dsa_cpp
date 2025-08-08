#include <bits/stdc++.h>
using namespace std;

Node* flatten(Node* head) {
    if(head == NULL) return head;

    Node* curr = head;
    while(curr != NULL) {
        if(curr->child != NULL) {
            //1
            Node* next = curr->next;
            curr->next = flatten(curr->child);
            curr->next->prev = curr;
            curr->child = NULL;

            //2
            while(curr->next != NULL) {
                curr = curr->next;
            }

            //3
            if(next != NULL) {
                curr->next = next;
                next->prev = curr;
            }
        }
        curr = curr->next;
    }

    return head;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif



	return 0;
}