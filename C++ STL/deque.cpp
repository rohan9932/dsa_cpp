#include <bits/stdc++.h>
using namespace std;

int main() { 
	// IN A DEQUE WE CAN DO ALL THE OPERATIONS FRONT AND BACK

	//-------------Initialize-------------
	// deque<int> d;
	deque<int> d = {1, 2, 3, 4, 5};


	//-------------Enter Elements----------
	// d.push_back(1); 
	// d.push_back(2);
	// d.push_front(5);
	// d.push_front(3);

	// d.pop_back();
	// d.pop_front();


	//-----------Print values-------------
	for(int val: d) {
		cout << val << " ";
	}
	cout << "\n";

	cout << d[2] << "\n";

	//ALL THE VECTOR FUNCTIONS ARE AVAILABLE HERE AS WELL

	//WE CAN'T GET RANDOM VALUE IN A LIST(AS IT'S A DOUBLY LINKED LIST) WHERE WE CAN GET IT IN A DEQUE(AS IT IS A DYNAMIC ARRAY)


	return 0;
}