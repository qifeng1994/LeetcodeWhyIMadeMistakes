//self-study note for the youtube video made by Bo Qian, really appreciate it
//Advanced Cpp playlist:https://youtu.be/7arYbAhu0aw
#include<string>
#include<iostream>
using namespace std;
namespace const_
{
	//const is a compile time constraint that an object can not be modified
	const int i = 9; //i is const, i=6; will make error
	const int* p1 = &i; //data is const, pointer is not, *p1=6 will change data and make error
	int* const p2;  // pointer is const, data is not
	const int* const p3;  // data and pointer are both const

	// If const is on the left  of *, data is const
	// If const is on the right of *, pointer is const

	class Dog {
		int age;
		string name;
	public:
		Dog() { age = 3; name = "dummy"; }

		// const parameters
		void setAge(const int& a) { age = a; }
		void setAge(int& a) { age = a; }

		// Const return value
		const string& getName() { return name; }
		
		void printDogName() const { cout << name << " const" << endl; } // const function
		void printDogName() { cout << getName() << " non-const" << endl; }
	};

	void test_dog()
	{
		Dog d;
		d.printDogName();

		const Dog d2;
		d2.printDogName(); //只有const对象才能调用const function
	}

	//TODO:P3 Logic Constness and Bitwise Constness

}

