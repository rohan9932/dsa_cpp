#include <iostream>
using namespace std;

// returntype funcName() {
//     code;
// }

// sum of 2 nums
double sum(double a, double b) { // parameters
    double sum = a + b;
    return sum;
}

// min of 2 nums
double minOfTwo(double a, double b) {
    double min = a;
    if (b < a) {
        min = b;
    }
    return min;
}

int main() {
    int a = 5;
    int b = 10;

    cout << sum(5 , 3) << "\n";

    cout << minOfTwo(4.5, 2.1) << "\n"; // arguments

    return 0;
}