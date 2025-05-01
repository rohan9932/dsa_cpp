#include <bits/stdc++.h>
using namespace std;

bool isValidParanthesis(string str) {
	stack<char> s;

	for(char ch: str) {
		if(ch == '(' || ch == '{' || ch == '[') {
			s.push(ch);
		} else { //closing brackets
			if(s.empty()) return false;

			if((ch == ')' && s.top() == '(') || (ch == '}' && s.top() == '{') || (ch == ']' && s.top() == '[')) {
				s.pop();
			} else { //no match
				return false;
			}
		}
	}

	if(!s.empty()) return false;

	return true;
}

int main() {

	cout << isValidParanthesis("{{{}]]") << "\n";
	cout << isValidParanthesis("{[()]}") << "\n";

	return 0;
}