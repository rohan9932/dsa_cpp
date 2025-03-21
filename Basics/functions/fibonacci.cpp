#include <iostream>
using namespace std;

int fibonacci(int n) {
    int a = 0, b = 1;
    int  c;
    for (int i = 1; i <= n-2; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cout << "Enter nth num: ";
    cin >> n;

    cout << fibonacci(n) << "\n";

    return 0;
}