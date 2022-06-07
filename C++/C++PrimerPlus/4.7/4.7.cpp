//指针
#include <iostream>
using namespace std;

int main()
{
    //4.15初始化指针的方法
    int intt1 = 1;
    int* ptr1;
    ptr1 = &intt1;

    int intt2 = 2;
    int* ptr2 = &intt2;

    int* ptr3 = new int;
    *ptr3 = 3;
    delete ptr3;

    int* ptr4 = new int[10]; //指针指向数组的第一个元素
    delete[]ptr4; //删除动态数组需要注意[]

    char charr1[]{ "qifeng" };
    char* ptr5 = charr1;
    cout << "address of ptr1 = " << ptr1 << endl;
    cout << "value of ptr5 = " << ptr5 << endl;
    cout << "address of ptr5 = " << (int*)ptr5 << endl<<endl; //强制类型转换

    struct nstruct
    {
        int data1;
        int data2;
    };
    nstruct demo{ 1,2 };
    nstruct* ptr6 = &demo;
    cout << "data1 of demo is " << (*ptr6).data1 << endl;
    cout << "data2 of demo is " << ptr6->data2 << endl;



}