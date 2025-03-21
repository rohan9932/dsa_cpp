#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums[] = {50, 3, 23, -15, -100};
    int sz = sizeof(nums) / sizeof(int);
    int smallest = INT_MAX; // it means positive inifinity int number
    int index = 0;

    for (int i = 0; i < sz; i++) {
        // if(nums[i] < smallest) {
        //     smallest = nums[i];
        // }

        // min function
        smallest = min(nums[i], smallest);
        if(nums[i] == smallest) {
            index = i;
        }
    }

    cout << "The smallest number in the array is: " << smallest << " and the index of it is: " << index << "\n";

    return 0;
}