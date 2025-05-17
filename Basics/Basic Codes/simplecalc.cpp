#include <iostream>
using namespace std;

int main() {
    int a, b, sum, sub, product, div;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    sum = a + b;
    sub = a - b;
    product = a * b;
    div = a / b;

    cout << "Sum is: " << sum << "\n";
    cout << "Substract is: " << sub << "\n";
    cout << "Product is: " << product << "\n";
    cout << "Division is: " << div << "\n";

    return 0;
}