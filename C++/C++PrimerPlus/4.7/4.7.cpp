//ָ��
#include <iostream>
using namespace std;

int main()
{
    //4.15��ʼ��ָ��ķ���
    int intt1 = 1;
    int* ptr1;
    ptr1 = &intt1;

    int intt2 = 2;
    int* ptr2 = &intt2;

    int* ptr3 = new int;
    *ptr3 = 3;
    delete ptr3;

    int* ptr4 = new int[10]; //ָ��ָ������ĵ�һ��Ԫ��
    delete[]ptr4; //ɾ����̬������Ҫע��[]

    char charr1[]{ "qifeng" };
    char* ptr5 = charr1;
    cout << "address of ptr1 = " << ptr1 << endl;
    cout << "value of ptr5 = " << ptr5 << endl;
    cout << "address of ptr5 = " << (int*)ptr5 << endl<<endl; //ǿ������ת��

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