#pragma once
#ifndef STUDENT
#define STUDENT

#include<iostream>
#include<string>


using namespace std;

class Student
{
//ѧ������������has-a��ϵ�������˽�м̳�(����ע���д���ȶ)
private:
	string name;
public:
	Student(string str);
};
#endif // !STUDENT
