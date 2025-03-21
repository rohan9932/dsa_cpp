#include <iostream>
using namespace std;

int sumDigits(int num) {
    int sum = 0, digit;
    while (num != 0) {
        digit = num % 10;
        num = num / 10;
        sum += digit;
    }
    return sum;
}

int main() {
    int num, sum;
    cout << "Enter a number: ";
    cin >> num;

    sum = sumDigits(num);
    cout << "The sum of the digits is: " << sum << "\n";

    return 0;
}