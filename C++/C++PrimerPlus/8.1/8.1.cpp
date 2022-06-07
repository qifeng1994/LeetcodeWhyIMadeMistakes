//内联函数
#include <iostream>
using namespace std;
inline void func() { cout << "this is an inline function" << endl; } //内联函数通常把函数原型和定义放在一起
int main()
{
    func();
    return 0;
}