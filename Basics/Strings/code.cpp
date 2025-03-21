#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif

	// your code goes here

	//---------CHAR ARRAYS--------
	// char str[20];
	// // char str2[] = "hello"; //string literals
	// // cout << strlen(str2) << "\n";

	// // cin >> str; //ignores after spaces

	// cin.getline(str, 20); // cin.getline(str, len, delimiter?)
	// // cout << "Output: " << str << "\n";

	// for(int i = 0; i < strlen(str); i++) {
	// 	cout << str[i] << "  ";
	// }


	//----------STRINGS-----------
	string str = "hello"; //dynamic => can resize in runtime
	cout << str << "\n";

	// str = "Nice to meet you.";
	// cout << str << "\n";

	string str2 = "world";

	string str3 = str + str2;

	//input
	getline(cin, str);

	cout << str << "\n";
	cout << (str == str2) << "\n";
	cout << (str > str2) << "\n";

	cout << str3.length() << "\n";


	//LOOPS IN A STRING
	for(int i = 0; i < str3.length(); i++) {
		cout << str3[i] << " ";
	}
	cout << "\n";

	//or,
	for(char ch: str3) {
		cout << ch << " ";
	}
	cout << "\n";




	return 0;
}