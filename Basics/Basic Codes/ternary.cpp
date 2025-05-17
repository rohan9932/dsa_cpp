#include <iostream>
using namespace std;

int main() {

    // structure
    // condition ? stt1 : strr2;

    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    cout << (num >= 0 ? "positive" : "negative") << "\n"; // ternary statement

    int i = 1;
    while (i <= num) {
        cout << i << " ";
        i++;
    }
    cout << "\n";

    return 0;
}