#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    bool isPrime = true;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        cout << "The number is a prime number.\n";
    } else {
        cout << "The number is not a prime number.\n";
    }

    return 0;
}