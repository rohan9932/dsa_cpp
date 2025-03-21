#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums[] = {50, 3, 23, -15, -100};
    int sz = sizeof(nums) / sizeof(int);
    int largest = INT_MIN; // it means negative inifinity int number
    int index = 0;

    for (int i = 0; i < sz; i++) {
        largest = max(nums[i], largest);
        if (nums[i] == largest) {
            index = i;
        }
    }

    cout << "The largest number in the array is: " << largest << " and the index of it is: " << index << "\n";

    return 0;
}