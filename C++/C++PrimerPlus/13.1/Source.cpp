#include"Header.h"
#include<iostream>

using namespace std;

BaseClass::BaseClass(int a, int b)
{
	data1 = a;
	data2 = b;
}

DerivedClass::DerivedClass(int c, BaseClass bc) :BaseClass(bc) //将参数bc从派生类构造函数传递给基类构造函数
{
	data3 = c;
}

void BaseClass::show() const
{
	cout << "From base class : data1 = " << data1 << " data2 = " << data2 << endl;
}

void DerivedClass::show() const 
{
	cout << "Frome derived class : data3 = " << data3<<" "; 
	BaseClass::show(); //派生类如果想访问基类的私有成员，必须用基类的方法
}