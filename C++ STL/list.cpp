#include <bits/stdc++.h>
using namespace std;

int main() { 
	// IN A LIST WE CAN DO ALL THE OPERATIONS FRONT AND BACK

	//-------------Initialize-------------
	// list<int> l;
	list<int> l = {1, 2, 3, 4, 5};


	//-------------Enter Elements----------
	// l.push_back(1); 
	// l.push_back(2);
	// l.push_front(5);
	// l.push_front(3);

	// l.pop_back();
	// l.pop_front();


	//-----------Print values-------------
	for(int val: l) {
		cout << val << " ";
	}
	cout << "\n";

	// cout << l[2] << "\n"; // it will give error as it's a doubly linked list and it's random value can't be accessed

	//ALL THE VECTOR FUNCTIONS ARE AVAILABLE HERE AS WELL


	return 0;
}