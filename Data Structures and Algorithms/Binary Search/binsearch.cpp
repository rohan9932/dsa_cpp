#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int tar) {
    int st = 0, end = arr.size() - 1, mid;
    while (st <= end) {
        mid = (st + end) / 2; 
        if(tar > arr[mid]) {
            st = mid + 1;
        } else if(tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> arr1 = {-1, 0, 3, 4, 5, 6, 7, 9, 12}; //odd
    int tar1 = 3;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; //even
    int tar2 = 0;

    cout << binarySearch(arr1, tar1) << "\n";
    cout << binarySearch(arr2, tar2) << "\n";

    return 0;
}