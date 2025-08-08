#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int>& heights) {
	int maxArea = 0;
	for(int i = 0; i < heights.size(); i++) {
		int minHeight = heights[i];
		for(int j = i; j < heights.size(); j++) {
			minHeight = min(minHeight, heights[j]);
			int area = minHeight*(j-i+1);
			maxArea = max(maxArea, area);
		}
	}

	return maxArea;
}

int optimal(vector<int>& heights) {
	int n = heights.size();
	stack<int> s;
	vector<int> r_smaller(n, n);
	vector<int> l_smaller(n, -1);

	for(int i=n-1; i>=0; i--) { //right smaller
		while(!s.empty() && heights[i] <= heights[s.top()]) {
			s.pop();
		}

		if(!s.empty()) r_smaller[i] = s.top();
		s.push(i);
	}

	while(!s.empty()) s.pop(); //cleaning the stack

	for(int i=0; i<n; i++) { //left smaller
		while(!s.empty() && heights[i] <= heights[s.top()]) {
			s.pop();
		}

		if(!s.empty()) l_smaller[i] = s.top();
		s.push(i);
	}

	int ans = 0;
	for(int i=0; i<n; i++) {
		int width = r_smaller[i] - l_smaller[i] - 1;
		int currArea = heights[i] * width;
		ans = max(currArea, ans);
	}
	return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> heights = {2, 1, 5, 6, 2, 3};
	cout << optimal(heights) << "\n";


	return 0;
}