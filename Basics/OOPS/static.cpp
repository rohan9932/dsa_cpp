#include <bits/stdc++.h>
using namespace std;

void fun() {
	static int x = 0;
	cout << x << "\n";
	x++;
}

class A {
public: 
	static int x;

	void increaseX() {
		x++;
	}
};

int A::x;

int main() {
	fun();
	fun();
	fun();

	A obj1;
	A obj2;

	obj1.x = 0;
	cout << obj1.x << "\n";
	obj1.increaseX();
	cout << obj1.x << "\n";

	obj2.x = 200;
	cout << obj2.x << "\n";
	cout << obj1.x << "\n";


	return 0;
}