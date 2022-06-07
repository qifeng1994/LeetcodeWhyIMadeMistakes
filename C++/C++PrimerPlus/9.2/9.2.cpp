//new定位运算符，指定通过new创建的heap的位置
#include<new>
#include <iostream>
using namespace std;
int main()
{
    char buffer[8];
    int* ptr1 = new int[2];
    int* ptr2 = new (buffer)int[2];
    ptr1[0] = ptr2[0] = 1;
    cout << "static address = " << &buffer << endl << "heap address = " << ptr1 << endl << "ptr2 address = " << ptr2 << endl;
    delete[]ptr1;
    return 0;
}

