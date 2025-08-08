#include <bits/stdc++.h>
using namespace std;

int main() {
    int marks[5];
    int sz = sizeof(marks) / sizeof(int);

    for (int i = 0; i < sz; i++) {
        cin >> marks[i];
    }

    for (int i = 0; i < sz; i++) {
        cout << marks[i] << "\n"; // 0 to size - 1
    }

    return 0;
}