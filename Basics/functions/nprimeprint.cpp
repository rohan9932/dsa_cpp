#include <iostream>
using namespace std;

bool prime(int num) {
    bool isPrime = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            isPrime = false;
        }
    }
    return isPrime;
}

int printPrimeNums(int n) {
    for (int i = 2; i <= n ; i++) {
        if (prime(i)) {
            cout << i << " ";
        }
    }
    return 0;
}

int main() {
    int n;
    cout << "Enter nth number: ";
    cin >> n;

    printPrimeNums(n);
    cout << "\n";
    
    return 0;
}