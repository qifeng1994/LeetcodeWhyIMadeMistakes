//����ָ�� *ptr(data)��������������
#include <iostream>
using namespace std;
void func1(int (*ptr)(int)); //ptr��һ��ָ������ָ��
int func2(int);
int* func3(int); //func(int)��һ������ָ��ĺ���
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