#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 2, 33, 2, 8, 7};
    int size = sizeof(arr) / sizeof(int);
    int target;
    cout << "Enter the targeted number: ";
    cin >> target;

    int targeted_num_index = linearSearch(arr, size, target);
    cout << "The targeted number's index is: " << targeted_num_index << "\n";
    return 0;
}  