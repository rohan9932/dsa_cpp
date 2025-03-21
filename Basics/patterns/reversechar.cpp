#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch = 'A'; // initializes the char to A
        ch += i; // then updates the starting char according to the line
        for (int j = i + 1; j > 0; j--) {
            cout << ch << " ";
            ch--;
        }
        cout << "\n";
    }

    return 0;
}