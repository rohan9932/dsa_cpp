#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;

    if (N == 0) {
        cout << "N is zero.";
    } else if (N % 2 == 0) {
        cout << "N is even.\n";
    } else {
        cout << "N is odd.\n";
    }

    return 0;
}