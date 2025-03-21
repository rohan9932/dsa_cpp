#include <bits/stdc++.h>
using namespace std;

void changeA(int* ptr) {
    *ptr = 20; // access value of the ptr 
}

void changeAref(int &a) {
    a = 30;
}

int main() {
    // int a = 50;
    // char ch = 'b';
    // int* ptr = &a;

    // // cout << &a << "\n";
    // // cout << &ch << "\n";
    // // cout << ptr << "\n";
    // // cout << &ptr << "\n";

    // int** ptr2 = &ptr;
    // cout << ptr2 << "\n";

    // cout << *ptr << "\n"; // Dereference value
    // cout << **ptr2 << "\n"; 

    // int* ptr = NULL; 
    // cout << ptr << "\n";

    // int a = 10;
    // changeA(&a);

    // cout << a << "\n";

    // changeAref(a);
    
    // cout << a << "\n";

    int arr[] = {1, 2, 3, 4, 5};

    // cout << *arr << "\n"; // pointer 

    int a = 10;
    int* ptr = &a;
    int* ptr2 = ptr + 2;

    // ptr++;
    // cout << ptr << "\n";

    // ptr--;
    // ptr--;
    // cout << ptr << "\n";

    // ptr += 2; // 2int == 8B
    // cout << ptr << "\n";

    // cout << *arr << "\n"; //1
    // cout << *(arr+1) << "\n"; //2
    // cout << *(arr+2) << "\n"; //3
    // cout << *(arr+3) << "\n"; //4
    // cout << *(arr+4) << "\n"; //5

    cout << (ptr != ptr2) << "\n";


    return 0;
}