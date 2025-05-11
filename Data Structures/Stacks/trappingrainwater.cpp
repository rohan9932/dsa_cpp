#include <bits/stdc++.h>
using namespace std;

int approach1(vector<int>& heights) {
	int n = heights.size();
	vector<int> l_max(n, 0);
	vector<int> r_max(n, 0);
	int ans = 0;

	l_max[0] = heights[0];
	r_max[n-1] = heights[n-1];

	for(int i = 1; i < n; i++) {
		l_max[i] = max(l_max[i-1], heights[i]);
	}
	for(int i = n-2; i >= 0; i--) {
		r_max[i] = max(r_max[i+1], heights[i]);
	}

	for(int i = 0; i < n; i++) {
		ans += min(l_max[i], r_max[i]) - heights[i];
	}

	return ans;
}

int approach2(vector<int>& heights) {
	int ans = 0;
	int l_max = 0, r_max = 0, l = 0, r = heights.size() - 1;

	while(l < r) {
		l_max = max(l_max, heights[l]);
		r_max = max(r_max, heights[r]);

		if(l_max < r_max) {
			ans += l_max - heights[l];
			l++;
		} else {
			ans += r_max - heights[r];
			r--;
		}
	}

	return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> v = {4, 2, 0, 3, 2, 5};

	cout << approach2(v) << "\n";

	return 0;
}