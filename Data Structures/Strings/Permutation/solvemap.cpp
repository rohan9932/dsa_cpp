#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
	map<char, int> freq;
	for(int i = 0; i < s1.length(); i++) {
		freq[s1[i]]++;
	}

	for(int i = 0; i < s2.length(); i++) {
		int winIdx = 0, idx = i;

		map<char, int> winFreq;
		while((winIdx < s1.length()) && (idx < s2.length())) {
			winFreq[s2[idx]]++;
			winIdx++, idx++;
		}

		if(freq == winFreq) {
			return true;
		}
	}

	return false;
}

int main() {
	string s1 = "ab" , s2 = "eidboaooo";
	if(checkInclusion(s1, s2)) {
		cout << "ase" << "\n";
	} else {
		cout << "nai" << "\n";
	}

	return 0;
}