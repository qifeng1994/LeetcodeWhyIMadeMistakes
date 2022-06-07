#pragma once
#ifndef STUDENT
#define STUDENT

#include <string>
using namespace std;

class Student :private string //私有继承，基类的公有方法成为派生类的私有方法
{
public:
	explicit Student(string& str):string(str){} //explicit表示初始化对象的时候必须用显式构造函数
};
#endif // !STUDENT
