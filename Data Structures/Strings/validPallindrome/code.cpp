#include <bits/stdc++.h>
using namespace std;

// bool isAlphanumeric(char ch) {
//     if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57)) {
//         return true;
//     } else {
//         return false;
//     }
// }

bool isPalindrome(string s) {
    int n = s.size();
    int st = 0, end = n-1;

    while (st < end) {
        if(!iswalnum(s[st])) {
            st++;
            continue;
        } 
        if(!iswalnum(s[end])) { // iswalnum() checks if a char is alphanumeric or not
            end--;
            continue;
        }

        if(tolower(s[st]) != tolower(s[end])) {
            return false;
        }
        st++;
        end--;
    }

    return true;
}

int main() {
	string s;
	getline(cin, s);

	if(isPalindrome(s)) {
		cout << "Pallindrome" << "\n";
	} else {
		cout << "Not Pallindrome" << "\n";
	}

	return 0;
}