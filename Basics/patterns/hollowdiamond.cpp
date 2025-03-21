#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    //top
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){ // spaces 1
            cout << " ";
        }
        cout << "*"; //star
        if(i != 0){
            for(int j = 0; j < (2*i)-1; j++){ // inner space
                cout << " "; 
            }
            cout << "*"; //star2
        }
        cout << "\n";
    }
    
    //bottom
    for(int i = 0; i < n-1; i++) { // 0 to n-2
        for(int j = 0; j < i+1; j++){
            cout << " ";
        }
        cout << "*";
        if (i != n-2) {
            for(int j = 0; j < (2*(n-i))-5; j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}