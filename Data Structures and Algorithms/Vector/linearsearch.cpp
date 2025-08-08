#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& vec, int target) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> vec = {4, 5, 2, 3, 1, 0};
    int target;
    cout << "Enter the targeted number: ";
    cin >> target;

    int targeted_num_index = linearSearch(vec, target);
    cout << "The targeted number's index is: " << targeted_num_index << "\n";
    return 0;
}