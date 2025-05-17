#include <iostream>
using namespace std;

int main() {
    int N, evenSum = 0;
    cout << "Enter a number: ";
    cin >> N;

    for(int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        }
    }
    cout << "The sum of even numbers is: " << evenSum << "\n";

    return 0;
}