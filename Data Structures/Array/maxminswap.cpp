#include <bits/stdc++.h>
using namespace std;

int main() {
    int max = INT_MIN, min = INT_MAX, max_index = 0, min_index = 0;
    double arr[] = {1.7, 2.5, 3.9, 4.6, 5.1};
    int size = sizeof(arr) / sizeof(double);

    // find max and it's index in array
    for (int i = 0; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }

    // find min and it's index in array
    for(int i = 0; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }

    swap(arr[max_index], arr[min_index]);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}