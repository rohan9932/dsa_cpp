#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++){ //spaces
            cout << " ";
        }
        for (int j = 0; j < n-i; j++){ //numbers
            cout << i+1; // if we add " " after i+1 then we will get inverted pyramid
        }
        cout << "\n";
    }

    return 0;
}