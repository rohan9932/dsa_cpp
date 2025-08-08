#include <bits/stdc++.h>
using namespace std;

int main() {
    double arr[] = {5.5, 4.2, 3.7, 2.3, 1.9};
    double sum = 0, prod = 1;
    int size = sizeof(arr) / sizeof(double);

    for(int i = 0; i < size; i++) {
        sum += arr[i];
        prod *= arr[i];
    }

    cout << "The sum of the numbers in the array is: " << sum << "\n";
    cout << "The product of the numbers in the array is: " << prod << "\n";

    return 0;
}