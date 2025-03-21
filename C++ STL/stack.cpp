#include <bits/stdc++.h>
using namespace std;

int main() {
	//LAST IN FIRST OUT 
	//WE CAN COMPARE IT WITH BOOKS PLACED IN STACK ON TOP OF EACH OTHER. THAT'S WHY ONLY TO TOP ELEMENT(LAST INPUT) CAN BE REMOVED

	stack<int> s;

	s.push(1); //O(1)
	s.push(2);
	s.push(3);

	stack<int> s2;
	s2.swap(s); //Swap s values with s2

	cout << "s size: " << s.size() << "\n";
	cout << "s2 size: " << s2.size() << "\n";

	// cout << "Top = " << s.top() << "\n";
	while(!s2.empty()) {
		cout << s2.top() << " "; //O(1)
		s2.pop(); //O(1)
	}
	cout << "\n";

	return 0;
}