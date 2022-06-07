//函数指针 *ptr(data)的输出结果有问题
#include <iostream>
using namespace std;
void func1(int (*ptr)(int)); //ptr是一个指向函数的指针
int func2(int);
int* func3(int); //func(int)是一个返回指针的函数
int main()
{
    func1(func2);
    int data = 666;
    cout << "return value of func3 is " << *func3(data) << endl;
    auto ptr = func3;
    cout << "return value of ptr is " << *ptr(data) << endl;
    return 0;
}

void func1(int (*ptr)(int))
{
    cout << "value of pointer function is " << (*ptr)(666) << endl;
}

int func2(int data1)
{
    return data1;
}

int* func3(int data1)
{
    return &data1;
}