#include <bits/stdc++.h>
using namespace std;

int main() {
	//Largest Value -> Highest priority (Stays on top)
	//When poped a value the largest value is poped first

	priority_queue<int> pq;

	pq.push(5); //O(logn)
	pq.push(10);
	pq.push(1);
	pq.push(4);

	while(!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	cout << "\n";


	//reverse priority queue
	priority_queue<int, vector<int>, greater<int>> rpq; //priority_queue<data_type, vector<data_type>, functor<data_type>>

	rpq.push(5);
	rpq.push(10);
	rpq.push(1);
	rpq.push(4);

	while(!rpq.empty()) {
		cout << rpq.top() << "\n"; //O(1)
		rpq.pop(); //O(logn)
	}


	return 0;
}