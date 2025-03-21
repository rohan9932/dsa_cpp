#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    for (int i = 0; i < n; i++){
        char ch = 'A';
        ch += i;
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < n-i; j++){
            cout << ch;
        }
        cout << "\n";
    }

    return 0;
}