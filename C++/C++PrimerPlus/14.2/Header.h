#pragma once
#ifndef STUDENT
#define STUDENT

#include <string>
using namespace std;

class Student :private string //˽�м̳У�����Ĺ��з�����Ϊ�������˽�з���
{
public:
	explicit Student(string& str):string(str){} //explicit��ʾ��ʼ�������ʱ���������ʽ���캯��
};
#endif // !STUDENT
