#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<int>& a, vector<int>& b, int m, int n) {
	vector<int> c;
	int i = 0, j = 0;
	while(c.size() != m + n) {
		if(i < m) {
			if(a[i] < b[j]) {
				c.push_back(a[i]);
				i++;
			} else {
				c.push_back(b[j]);
				j++;
			}
		} else {
			c.push_back(b[j]);
			j++;
		}
	}
	return c;
}

void optimal(vector<int>& a, vector<int>& b, int m, int n) {
	int i = m-1, j = n-1, idx = m+n-1;
	while(i >= 0 && j >= 0) {
		if(a[i] > b[j]) {
			a[idx] = a[i];
			idx--;
			i--;
		} else {
			a[idx] = b[j];
			idx--;
			j--;
		}
	}

	while(j >= 0) {
		a[idx] = b[j];
		idx--;
		j--;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif

	// your code goes here
	vector<int> a = {4, 5, 6, 0, 0, 0}, b = {1, 2 , 3};
	int m = 3, n = 3;

	optimal(a, b, m, n);

	for(int i = 0; i < a.size(); i ++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;

}