#include <bits/stdc++.h>
using namespace std;

int length(int n) {
    int lengthCount = 0;
    while (n != 0) {
        lengthCount++;
        n /= 10;
    }
    return lengthCount;
}

int main() {
    int n, num_length, digit, reversed_num = 0;
    cout << "Enter a number: ";
    cin >> n;

    num_length = length(n);

    for(int i = num_length - 1; i >= 0; i--) {
        digit = n % 10;
        reversed_num += digit * pow(10, i);
        n = n / 10;
    }
    cout << "Reversed number: " << reversed_num << "\n";

    return 0;
}