#include <bits/stdc++.h>
using namespace std;

int main() {
	//MULTIMAP
	//keys can be duplicated and store multiple values

	multimap<string, int> mm;

	mm.emplace("ac", 100);
	mm.emplace("ac", 200);
	mm.emplace("ac", 150);
	mm.emplace("ac", 500);

	mm.erase(mm.find("ac"));
	for(auto p: mm) {
		cout << p.first << "  " << p.second << "\n";
	}
	cout << "\n";


	//UNORDERED MAP
	//stores values randomly

	//insert(), erase(), count() -> O(1)
	unordered_map<string, int> um;

	um["ac"] = 1000;
	um["laptop"] = 500;
	um["remote"] = 20;
	um["headphones"] = 50;

	um.insert({"camera", 25});
	um.emplace("tablet", 100);

	um.erase("ac"); 

	for(auto p: um) {
		cout << p.first << "  " << p.second << "\n";
	}
	cout << "\n";

	return 0;
}