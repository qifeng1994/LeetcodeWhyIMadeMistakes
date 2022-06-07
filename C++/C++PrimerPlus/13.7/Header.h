#pragma once
#ifndef BASE
#define BASE

#include<iostream>
class BaseClass
{
private:
	int* ptr1;
public:
	BaseClass();
	BaseClass(const BaseClass& bc);
	virtual ~BaseClass();

};

class HasClass:public BaseClass
{
private:
	int* ptr2;
public:

};
#endif // !BASE
