//基类与派生类
//利用virtual建立虚方法实现多态
#include"Header.h"
#include <iostream>
using namespace std;
int main()
{
    BaseClass bc ( 1,2 );
    DerivedClass* dc = new DerivedClass(3, bc); //声明指针并初始化
    DerivedClass ddc( 4,bc );
    BaseClass* ptr = &ddc; //声明指针

    bc.show();
    dc->show(); //子类用自己的虚方法
    dc->BaseClass::show(); //通过指针让子类对象调用父类的虚方法
    ddc.BaseClass::show(); //直接访问父类虚方法
    ptr->show(); //如果指针可以指向父类，那么也一定可以指向子类,这里调用的是子类show方法
    return 0;
}
