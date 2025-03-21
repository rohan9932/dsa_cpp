#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int n, r;
    float nCr;

    cout << "Enter n and r for determining the nCr: ";
    cin >> n >> r;

    nCr = factorial(n) / (factorial(r) * factorial(n-r));

    cout << "Binomial coefficient is: " << nCr << "\n"; 
    return 0;
}