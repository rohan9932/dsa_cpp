#include <bits/stdc++.h>
using namespace std;

int main() {
	//WE CAN THINK OF IT AS MATHS SET

	//insert(), count(), erase() -> O(logn)

	set<int> s;

	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(5);
	s.insert(6);

	s.insert(3);
	s.insert(5);

	cout << s.size() << "\n"; 
	//VALUES ARE STORED ONCE AND UNIQUELY IN SET. THAT'S WHY 3, 5 ARE NOT PRINTED AGAIN


	for(auto val: s) {
		cout << val << " ";
	}
	cout << "\n";

	//OTHER FUNCTIONS
	//should not be less than key (>= key)
	cout << "Lower Bound: " << *(s.lower_bound(4)) << "\n"; //RETURNS ITERATOR OF THE VALUE OR IF NOT FOUND ITERATOR OF JUST IMMEDIATE GREATER VALUE THAN IT
															//OR IF NOT FOUND ANY RETURNS s.end()

	//greater than key
	cout << "Upper bound: " << *(s.upper_bound(5)) << "\n";

	cout << "\n\n\n";

	//MULTISET
	multiset<int> ms;

	ms.insert(1);
	ms.insert(2);
	ms.insert(3);
	ms.insert(5);
	ms.insert(6);

	ms.insert(3);
	ms.insert(5);

	for(auto val: ms) {
		cout << val << " ";
	}
	cout << "\n";

	cout << "\n\n";

	//UNORDERED SET O(n)
	unordered_set<int> os;

	os.insert(1);
	os.insert(2);
	os.insert(3);
	os.insert(5);
	os.insert(6);

	os.insert(3);
	os.insert(5);

	for(auto val: os) {
		cout << val << " ";
	}
	cout << "\n";
	//lower_bound and upper_bound concepts are not available here


	return 0;

}