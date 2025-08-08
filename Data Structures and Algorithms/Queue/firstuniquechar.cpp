#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {

    unordered_map<char, int> m;
    queue<int> q;

    for(int i = 0; i < s.length(); i++) {
    	if(m.find(s[i]) == m.end()) q.push(i);
    	m[s[i]]++;
    	while(!q.empty() && m[s[q.front()]] > 1) q.pop();
    }
    return (q.empty())? -1 : q.front();
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string str = "rohan";

	cout << firstUniqChar(str) << "\n";

	return 0;
}