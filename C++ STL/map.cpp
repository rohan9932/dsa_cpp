#include <bits/stdc++.h>
using namespace std;

int main() {
	//KEY, VALUE PAIR. WE CAN COMPARE IT TO A TABLE

	//insert(), erase(), count() -> O(logn)

	map<string, int> m; //map<key_data_type, value_data_type> var

	m["ac"] = 1000;
	m["laptop"] = 500;
	m["remote"] = 20;
	m["headphones"] = 50;

	m.insert({"camera", 25});
	m.emplace("tablet", 100);

	m.erase("ac"); 

	for(auto p: m) {
		cout << p.first << "  " << p.second << "\n";
	}
	cout << "\n";
	//WE CAN SE THAT VALUES ARE PRINTED IN LEXICOGRAPHICAL ORDER
	//BY DEFAULT IN MAP KEYS ARE SORTED IN ASCENDING ORDER

	cout << "Count: " << m.count("laptop") << "\n"; //counts num of instances of key "laptop"


	//.find(key) returns iterator if found or returns m.end() if not found
	if(m.find("ac") != m.end()) {
		cout << "Found\n";
	} else {
		cout << "Not found\n";
	}

	//SIZE, EMPTY AS OTHERS


	return 0;
}