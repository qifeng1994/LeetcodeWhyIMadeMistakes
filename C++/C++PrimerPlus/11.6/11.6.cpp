
#include "Header.h"
#include <iostream>
using namespace std;
int main()
{
    //对象初始化的方式
    Stone stn1 = 15.0; //实际是用构造函数对成员数据进行了初始化，这种写法没有直接调用函数，被成为隐式转换
    stn1.show_pounds();
    stn1.show_stone();

    Stone stn2 = Stone(16); //显式强制类型转换
    Stone stn3(1, 1);
    stn3.show_pounds();
    
    //转换函数的使用
    Stone stn4(1, 1.6); //所谓初始化，就是在这一刻决定了使用的是哪个构造函数，成员数据是什么
    double cov_double = stn4;  
    cout << "convert to double = " << cov_double << " pounds.\n";
    cout << "convert to int = " << int(stn4) << " pounds.\n";
    return 0;
}
