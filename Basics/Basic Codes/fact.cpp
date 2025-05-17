#include <iostream>
using namespace std;

int main() {
    int N;
    double fact = 1;
    cout << "Enter a number: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        fact = fact * i;
    }
    cout << "Factorial of the number: " << fact << "\n";

    return 0;
}