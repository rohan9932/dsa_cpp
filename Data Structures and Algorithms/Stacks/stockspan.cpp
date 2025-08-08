#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int>& prices) {
	vector<int> ans;
	stack<int> s;
	int span;

	for(int i = 0; i < prices.size(); i++) {
		while(!s.empty() && prices[s.top()] <= prices[i]) s.pop();

		if(s.empty()) span = i + 1; 
		else span = i - s.top();

		s.push(i);
		ans.push_back(span);
	}

	return ans;
} 

int main() {
	vector<int> prices;
	int n;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int price;
		cin >> price;
		prices.push_back(price);
	}

	vector<int> spans = stockSpan(prices);

	for(int val: spans) {
		cout << val << " ";
	}
	cout << "\n";

	return 0;
}