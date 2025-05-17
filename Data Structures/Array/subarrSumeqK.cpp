#include <bits/stdc++.h>
using namespace std;

int subarraySumBruteForce(vector<int>& nums, int k) {
	int n = nums.size();
	int count = 0;

    for(int i = 0; i < n; i++) {
    	int sum = 0;
    	for(int j = i; j < n; j++) {
    		sum += nums[j];
    		if(sum == k) count++;
    	}
    }

    return count;
}

int subarraySum(vector<int>& nums, int k) {
	int n = nums.size();
	int count = 0;
	vector<int> pS(n);
	pS[0] = nums[0];
	for(int i = 1; i < n; i++) {
		pS[i] = pS[i-1] + nums[i];
	}

	unordered_map<int, int> m;
	for(int j = 0; j < n; j++) {
		if(pS[j] == k) count++;

		int val = pS[j] - k; //pS[i-1]
		if(m.find(val) != m.end()) {
			count += m[val];
		}

		m[pS[j]]++;
	}

	return count;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> vec = {9, 0, 4, 20, 3, 10, 5};

	cout << subarraySum(vec, 33) << "\n";

	return 0;
}