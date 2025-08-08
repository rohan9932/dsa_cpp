#include <iostream>
#include <vector>
using namespace std;

int main() {
    // vector<int>vec(5,0);
    // for(int i : vec) { // for each loop
    //     cout << i << "\n";
    // }

    // vec.push_back(25);
    // vec.push_back(55);
    // vec.push_back(99);

    // cout << vec.size() << "\n";

    // vec.pop_back();
    // cout << vec.size() << "\n";

    vector<int>vect;
    vect.push_back(0);
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);

    cout << vect.size() << "\n";
    cout << vect.capacity() << "\n";
    
    return 0;
}