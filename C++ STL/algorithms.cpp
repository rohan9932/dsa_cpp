#include <bits/stdc++.h>
using namespace std;

//custom comparator (here we are writing a custom comparator for sorting the pairs in descending order according second value)
bool comparator(pair<int, int> p1, pair<int, int> p2) {
	if(p1.second > p2.second) return true;
	if(p1.second < p2.second) return false;

	if(p1.first > p2.first) return true;
	else return false;
}

int main() {
	//SORT

	int arr[5] = {5, 1, 3, 2, 6};

	sort(arr, arr + 5);

	for(auto val: arr) {
		cout << val << " ";
	}
	cout << "\n\n";


	vector<pair<int, int>> v = {{1,2}, {5, 1}, {3, 9}, {8, 9}};

	sort(v.begin(), v.end(), comparator);

	for(auto p: v) {
		cout << p.first << " " << p.second << "\n";
	}


	//REVERSE
	vector<int> v1 = {1, 2, 3, 4, 5};

	reverse(v1.begin()+2, v1.end());

	for(auto val: v1) {
		cout << val << " ";
	}
	cout << "\n\n";

	//MAX MIN ELEMENTS
	cout << *(max_element(v1.begin(), v1.end())) << "\n";
	cout << *(min_element(v1.begin(), v1.end())) << "\n";


	//BINARY SEARCH
	cout << binary_search(v1.begin(), v1.end(), 1) << "\n"; // data should be sorted


	//NEXT_PERMUTATION
	string s = "abc";
	next_permutation(s.begin(), s.end());

	cout << s << "\n";


	//PREV_PERMUTATION
	string s1 = "bca";
	prev_permutation(s1.begin(), s1.end());

	cout << s1 << "\n";

	cout << "\n\n\n";


	//POPCOUNT
	//SUPPOSE N's bin is = 000000........1111
	//so it's builtin popcount will be 4 as it has 4 1's
	int n = 5;
	long int n2 = 15;
	long long int n3 = 15;

	cout << __builtin_popcount(n) << "\n";
	cout << __builtin_popcountl(n2) << "\n";
	cout << __builtin_popcountll(n3) << "\n";

	return 0;
}