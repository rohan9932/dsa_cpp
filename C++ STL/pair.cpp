#include <bits/stdc++.h>
using namespace std;

int main() {
	pair<int, int> p = {5, 4};
	pair<char, int> p2 = {'R', 5};
	pair<string, pair<int, int>> p3 = {"Rohan", {1, 3}};

	vector<pair<int, int>> v = {{2, 3}, {3 ,5}, {5, 9}};

	v.push_back({9, 3}); //assumes object is created and just inserts
	v.emplace_back(9, 3); //in-place object create


	cout << p3.first << "\n";
	cout << p3.second.first << "\n";
	cout << p3.second.second << "\n";

	for(auto p: v) {
		cout << p.first << " ";
		cout << p.second << "  ";
	}
	cout << "\n";


	return 0;
}