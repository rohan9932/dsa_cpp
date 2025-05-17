#include <iostream>
using namespace std;

int main() {
    int i = 1, n, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (i <= n) {
        if (i % 2 != 0) {
            sum += i;
        }
        i++;
    }
    cout << "The sum is: " << sum << "\n";

    return 0;
}