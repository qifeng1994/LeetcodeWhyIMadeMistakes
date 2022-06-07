#pragma once
#ifndef STUDENT
#define STUDENT

#include<iostream>
#include<string>


using namespace std;

class Student
{
//学生有姓名，是has-a关系，因此用私有继承(这条注释有待商榷)
private:
	string name;
public:
	Student(string str);
};
#endif // !STUDENT
