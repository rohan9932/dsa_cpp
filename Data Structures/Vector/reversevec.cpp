#include <iostream>
#include <vector>
using namespace std;

void reverseVec(vector<int>& vec) {
    int start = 0, end = vec.size() - 1;
    while(start < end) {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int>vec = {5, 4, 3, 2, 1, 0};

    reverseVec(vec);
    
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "  ";
    }
    cout << "\n";

    return 0;
} 