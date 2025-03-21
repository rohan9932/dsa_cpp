#include <bits/stdc++.h>
using namespace std;


// brute force approach
int main() {
    int n = 5, currentSum, maxSum = 0;
    int arr[] = {1, 2, 3, 4, 5};

    for(int st= 0; st < n; st++) { // for 0 to n-1 index
        currentSum = 0;
        for(int end = st; end < n; end++) { // st to n-1
            // for(int i = st; i <= end; i++) { // start to end all element 
            //     cout << arr[i]; // print each subarray element
            // }
            // cout << " ";
            currentSum += arr[end];
            maxSum = max(currentSum, maxSum);
        }
    }

    cout << "Maximum Subarray sum is: " << maxSum << "\n";

    return 0;
}