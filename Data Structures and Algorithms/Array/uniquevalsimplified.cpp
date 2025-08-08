#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4, 5, 5, 6, 6, 7, 8};
    int size = sizeof(arr) / sizeof(int);

    for(int i = 0; i < size; i++) {
        bool isUnique = true;
        
        // again watching if there is a duplicate value
        for(int j = 0; j < size; j++) {
            if(j != i && arr[i] == arr[j]) {
                isUnique = false;
            }
        }

        if(isUnique) {
            cout << arr[i] << "  ";
        }
    }
    cout << "\n";

    return 0;
}