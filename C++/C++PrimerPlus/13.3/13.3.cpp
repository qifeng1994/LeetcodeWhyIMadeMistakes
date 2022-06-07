//指针和类

#include <iostream>
using namespace std;

//声明类
class A
{
public:
    int data1;
    A(int a);
    void show();
};

//定义类
A::A(int a)
{
    data1 = a;
}

void A::show()
{
    cout << "data1 : " << data1<<endl;
}


int main()
{
    A A1(1); //用构造函数实例化一个对象
    A1.show();

    //要么先实例化一个对象，然后让指针指向它
    A* ptr1 = &A1; //指针指向一个对象
    cout << "use ptr1 to show : ";
    ptr1->show();

    //要么先让指针指向一个new对象，然后再把内容转移给实例
    A* ptr2 = new A ( 2 ); 
    cout << "use ptr2 to show : ";
    ptr2->show();
    A A3 = *ptr2; //把指针的内容赋值给一个变量


    return 0;
}