#include <bits/stdc++.h>
using namespace std;

bool isFreq(int freq1[], int freq2[]) {
	for(int i = 0; i < 26; i++) {
		if(freq1[i] != freq2[i]) {
			return false;
		}
	}

	return true;
}


bool checkInclusion(string s1, string s2) {
	int freq[26] = {0};
	for(int i = 0; i < s1.size(); i++) {
		freq[s1[i] - 'a']++;
	}

	int winSize = s1.length();

	for(int i = 0; i < s2.length(); i++) {
		int winIdx = 0, idx = i;
		int winFreq[26] = {0};

		while((winIdx < s1.length()) && (idx < s2.length())) {
			winFreq[s2[idx] - 'a']++;
			winIdx++, idx++;
		}

		if(isFreq(freq, winFreq)) {
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