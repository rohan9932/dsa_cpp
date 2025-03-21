#include <bits/stdc++.h>
using namespace std;

int main() {
	//LAST IN FIRST OUT
	//WE CAN COMPARE IT WITH QUEUE(SERIALS). AS WE ENTER THERE FROM LAST AND GET OUT FROM FIRST SO IN QUEUE ELEMENTS ARE SIMILARLY ENTERED FROM LAST AND POP FROM FIRST

	queue<int> q;

	q.push(1); //O(1)
	q.push(2);
	q.push(3);

	while(!q.empty()){
		cout << q.front() << " "; //O(1)
		q.pop(); //O(1)
	}

	//SIZE, EMPTY, SWAP SAME AS STACK

	return 0;
}