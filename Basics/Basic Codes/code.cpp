#include <iostream>
using namespace std;

int main() {
    int a;
    float PI = 3.14159f;
    a = 20; // here a is called an identifier
    cout << "Rohan Rahim" << "\n";
    cout << "Rohan\nRahim" << "\n";
    cout << a << "\n";
    cout << sizeof(a) << "\n"; // outputs size of the age variable
    cout << PI << "\n";

    char name = 'r';
    int val = name;
    cout << val << "\n";

    // explicit type casting
    double price = 150.99999932;
    int newPrice = (int)price;
    cout << newPrice << "\n";

    int age;
    cout << "Enter your age: ";
    cin >> age;

    cout << "Your age is: " << age << "\n";

    int b = 3;
    int c = 10;
    cout << ((float)c / b) << "\n";
    return 0;
}