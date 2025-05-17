#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, i = 1;
    cout << "Enter a number: ";
    cin >> n;

    while (i <= n) {
        sum += i;
        i++;
        if (i == 5) {
            break;
        }
    }
    cout << "The sum is: " << sum << "\n";

    return 0;
}