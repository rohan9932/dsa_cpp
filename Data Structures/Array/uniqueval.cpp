#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4, 5, 5, 6, 6, 7, 8};
    int val, cropped_arr_size;
    int size = sizeof(arr) / sizeof(int);
    int cropped_arr[size];
    bool isUnique = true;

    for(int i = 0; i < size; i++) {
        val = arr[i];

        // store arr values to the cropped arr
        cropped_arr_size = sizeof(cropped_arr) / sizeof(int);
        for(int j = 0; j < cropped_arr_size; j++) {
            cropped_arr[j] = arr[j];
        }

        // crop the value from the array
        cropped_arr_size -= 1; // reducing the cropped_arr size
        for(int j = i; j < cropped_arr_size; j++) {
            cropped_arr[j] = cropped_arr[j + 1]; // shifting the j+1 th value to the left
        }

        // check if there is a duplicate value in the array
        for(int j = 0; j < cropped_arr_size; j++) {
            if(cropped_arr[j] == val) {
                isUnique = false;
            }
        }

        if(isUnique) {
            cout << val << "  ";
        }

        isUnique = true; // reseting isUnique value
    }
    cout << "\n";

    return 0;
}