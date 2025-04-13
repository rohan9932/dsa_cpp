#include <bits/stdc++.h>
using namespace std;

class Teacher {
private:
	double salary;
public:
	Teacher() {
		cout << "This statement is from constructor\n";
	}
	//properties/attributes
	string name;
	string dept;
	string subject;

	//methods/member functions
	void changeDept(string newDept) {
		dept = newDept;
	}

	//setter
	void setSalary(int s) {
		salary = s;
	}
	//getter
	double getSalary() {
		return salary;
	}
};

class Student {
public:
	//non-paramitarized
	Student() {
		dept = "Computer Science and Engineering";
	}

	//paramitarized
	Student(string name, float semester, string dept, string roll, double cgpa) {
		this->name = name;
		this->semester = semester;
		this->dept = dept;
		this->roll = roll;
		cgpaPtr = new double;
		*cgpaPtr = cgpa;
	}

	//copy constructor
	Student(Student &orgObj) {
		this->name = orgObj.name;
		this->semester = orgObj.semester;
		this->dept = orgObj.dept;
		this->roll = orgObj.roll;
		cgpaPtr = new double;
		*cgpaPtr = *orgObj.cgpaPtr;
	}

	//properties/attributes
	string name;
	float semester;
	string dept;
	string roll;
	double* cgpaPtr;

	//methods/member functions
	void changeDept(string newDept) {
		dept = newDept;
	}

	void getInfo() {
		cout << "Name: " << name << "\n";
		cout << "Semester: " << semester << "\n";
		cout << "Department: " << dept << "\n";
		cout << "Roll: " << roll << "\n";
		cout << "CGPA: " << *cgpaPtr << "\n";
 	}

 	//Destructor
 	~Student() {
 		delete cgpaPtr; //if don't delete the dynamically allocated memory it can cause "memory leak"
 	}
};
 
class Account {
private:
	double balance;
	string password; //data hiding

public:
	string accountId;
	string username;
};



//---------------Inheritence--------------- 

//single inheritence
class Person {
public:
	string name;
	int age;

	Person(string name, int age) {
		cout << "Parent" << "\n";
		this->name = name;
		this->age = age;
	}

	~Person() {
		cout << "Parent destructor\n"; 
	}
};

class Student : public Person {
public:	
	//name, age, rollNo
	int rollNo;

	Student(string name, int age, int rollNo) : Person(name, age) {
		cout << "child" << "\n";
		this->rollNo = rollNo;
	}

	void getInfo() {
		cout << "Name: " << name << "\n";
		cout << "Age: " << age << "\n";
		cout << "Roll No: " << rollNo << "\n";
	} 

	~Student() {
		cout << "Child destructor\n";
	}
};

class Teacher {
public:
	string subject;
	double salary;
};

//multiple inheritence
class GradStudent : public Student {
public:
	string researchArea;
};


//multi inheritence
class TA : public Student, public Teacher {};



//--------------Abstraction---------------
class Shape { //Abstract class
	virtual void draw() = 0; //pure virtual function
};

class Circle : public Shape {
public: 
	void draw() {
		cout << "Circle Draw\n";
	}
};


int main() {
	Teacher t1;
	t1.name = "Romana Yeasmin";
	t1.dept = "Arts and Sciences";
	t1.subject = "Math";
	t1.setSalary(70000);

	cout << t1.getSalary() << "\n";


	Student s1("Rohan Rahim", 1.1, "Computer Science and Engineering", "00724105101122", 3.9);

	Student s2(s1); //default copy constructor -invoke

	s1.getInfo();

	*(s2.cgpaPtr) = 4.00;
	s2.name = "Neha";
	s2.roll = "00724105101118";
	s2.getInfo();

	Student s1("Rohan Rahim", 20, 122);	
	s1.getInfo();

	GradStudent gs1;
	gs1.name = "Afia";

	cout << gs1.name << "\n"; 

	TA t1;
	t1.name = "Rohan Rahim";
	t1.subject = "CSE";

	cout << t1.name << " " << t1.subject << "\n";

	Circle c1;
	c1.draw();

	return 0;
}