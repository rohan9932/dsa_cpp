#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr1[] = {1, 2, 3, 4, 5}, arr2[] = {5, 23, 4, 22, 4 , 8, 9, 15, 17};
    int size_arr1, size_arr2;
    size_arr1 = sizeof(arr1) / sizeof(int);
    size_arr2 = sizeof(arr2) / sizeof(int);

    for(int i = 0; i < size_arr1; i++) {
        bool isIntersected = false;
        
        // looping through arr2 to check intersected value
        for(int j = 0; j < size_arr2; j++) {
            if(arr1[i] == arr2[j]) {
                isIntersected = true;
            }
        }

        if(isIntersected) {
            cout << arr1[i] << "  ";
        }
    }
    cout << "\n";

    return 0;
}