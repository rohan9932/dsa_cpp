#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for(int i = 0; i < n; i++) { // outer loop which will define the number of lines
        char ch = 'A';
        for (int j = 0; j < n; j++){ // inner loop which will define the logic of the element on that line
            cout << ch << " ";
            ch += 1;
        }
        cout << "\n";
    }

    return 0;
}