#include"Header.h"
#include<iostream>

using namespace std;

BaseClass::BaseClass(int a, int b)
{
	data1 = a;
	data2 = b;
}

DerivedClass::DerivedClass(int c, BaseClass bc) :BaseClass(bc) //������bc�������๹�캯�����ݸ����๹�캯��
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
	BaseClass::show(); //�������������ʻ����˽�г�Ա�������û���ķ���
}