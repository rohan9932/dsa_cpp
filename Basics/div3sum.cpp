#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;
    cout << "Enter a number: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) {
            sum += i;
        }
    }
    cout << "The sum is: " << sum << "\n";

    return 0;
}