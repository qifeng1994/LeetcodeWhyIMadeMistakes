//函数重载，返回类型可以不同，但特征标也必须不同
#include <iostream>
using namespace std;
void func(int);
void func(float);

int main()
{
    func(1);
    func(1.1f);
    return 0;
}

void func(int a)
{
    cout << "int data is " << a << endl;
}

void func(float a)
{
    cout << "float data is " << a << endl;
}