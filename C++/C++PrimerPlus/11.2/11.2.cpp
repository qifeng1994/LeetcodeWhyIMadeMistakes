//运算符重载
//友元函数的例子略过了 friend
//转换函数的例子略过了 operator typeName()
#include <iostream>
#include"Header.h"
using namespace std;

int main()
{
    Time t1{ 30,1 };
    Time t2{ 40,1 };
    t1.operator+(t2);
    t1.show();
    return 0;
}
