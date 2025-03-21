#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    for (int i = 0; i < n; i++){
        //spaces
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        //num1
        for(int j = 0; j < i + 1; j++) {
            cout << j + 1;
        }
        //num2
        for(int j = i; j > 0; j--) {
            cout << j;
        }
        cout << "\n";
    }

    return 0;
}