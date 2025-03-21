#include <iostream>
using namespace std;

int nsum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter nth number: ";
    cin >> n;

    cout << "The sum is: " << nsum(n) << "\n";
    return 0;
}