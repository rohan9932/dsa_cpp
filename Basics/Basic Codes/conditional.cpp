#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n >= 0) {
        cout << "N is positive." << "\n";
    } else {
        cout << "N is negative." << "\n";
    }
    
    return 0;
}