#include <bits/stdc++.h>
using namespace std;

int main() {
	//--------------Initialize a vector-------------

	vector<int> vec = {1, 2, 3, 4, 5};
	// vector<int> vec(3, 5); // initializes a 3 size vector with 5 
	// vector<int> vec2(vec); // initializes vec2 to vec values



	//---------------Vector functions----------------

	// vec.push_back(1); //enters a value to the last
	// vec.push_back(2);
	// vec.push_back(3);
	// vec.emplace_back(5); // same as push_back

	// vec.pop_back();//delets last element

	// cout << vec.size() << "\n"; // enters size(number of elements)
	// cout << vec.capacity() << "\n"; // shows capacity(number of elements it can hold)

	// cout << "Front " << vec.front() << " and back " << vec.back() << "\n"; // First and last elements

	// vec.erase(vec.begin() + 2);
	// vec.erase(vec.begin() + 1, vec.begin() + 3); // erase a range of nums vec.erase(start, end) where [start, end)

	// vec.insert(vec.begin() + 2, 500); // inserts a val to the position

	// vec.clear();

	// cout << "Is Empty: " << vec.empty() << "\n"; 


	//=======Vector Iterators==========

	// cout << *(vec.begin()) << " " << *(vec.end()) << "\n"; // begin points at first element's location and end points at last+1 location




	//------------Print a vector-------------------

	//===Normal===
	for(int val: vec) {
		cout << val << " ";
	}
	cout << "\n";

	//==Iterators==
	// vector<int>::iterator i;
	for(auto i = vec.begin(); i != vec.end(); i++) {
		cout << *(i) << " ";
	}
	cout << "\n";

	//reverse print
	// vector<int>::reverse_iterator it;
	for(auto it = vec.rbegin(); it != vec.rend(); it++) { // we can write just auto instead of vector<int>::reverse_iterator i;
		cout << *(it) << " ";
	}
	cout << "\n";



	return 0;
}