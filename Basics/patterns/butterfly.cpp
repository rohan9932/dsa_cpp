#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    //top 
    for (int i = 0; i < n; i++) {
        //star
        for (int j = 0; j < i+1; j++) {
            cout << "*";
        }
        //space
        for (int j = 2*(n-i-1); j > 0; j--) {
            cout << " ";
        }
        //star
        for (int j = 0; j < i+1; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    //bottom
    for (int i = 0; i < n; i++) {
        //star
        for(int j = 0; j < n-i; j++) {
            cout << "*";
        }
        //space
        for (int j = 0; j < 2*i ; j++) {
            cout << " ";
        }
        //star
        for(int j = 0; j < n-i; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}