#include "Header.h"
#include<iostream>
using namespace std;
void classs::add(int a, int b)
{
	cout << "a + b = " << a + b << endl;
}

void classs::show()const
{
	cout << "data1 is " << data1 << endl; //公开方法可以访问私有变量
	cout << "data2 is " << data2 << endl;
}

classs::classs()
{
	data1 = 'a';
	data2 = 1;
}

classs::classs(char c, int i)
{
	data1 = c;
	data2 = i;
}

classs::~classs()
{
	cout << "class deleted" << endl;
}

void classs::compare(classs& cls)
{
	if (cls.data2>data2)
	{
		cout << "max is " << cls.data2 << " address is " << &cls.data2 << endl;
	}
	else
	{
		cout << "max is " << this->data2 << " address is " << &(this->data2) << endl;
		cout << "max is " << data2 << " address is " << &data2 << endl;
	}

}