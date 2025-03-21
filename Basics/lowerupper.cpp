#include <iostream>
using namespace std;

int main() {
    char a;
    cout << "Enter a character: ";
    cin >> a;

    if (((int)a) >= 65 && ((int)a) <= 90) {
        cout << "Uppercase.\n";
    } else if (((int)a) >= 97 && ((int)a) <= 122) {
        cout << "Lowercase.\n";
    } else {
        cout << "Invalid Input!\n";
    }

    return 0;
}