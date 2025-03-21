#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int>vec = {2, 2, 1, 1, 1};
    int count;

    for(int val : vec) {
        count = 0;
        for(int val2 : vec) {
            if(val == val2) {
                count++;
            }
        }
        if(count > (vec.size()/2)) {
            cout << val << "\n";
            break;
        }
    }

    return 0;
}