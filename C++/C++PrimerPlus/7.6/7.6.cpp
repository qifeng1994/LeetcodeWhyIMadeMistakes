//极坐标和直角坐标相互转换
//这个是自己写的，跟程序清单7.13不太一样
#include <iostream>
#include<math.h>
using namespace std;
struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar* func1(rect* ptr);
rect* func2(polar* ptr);

int main()
{
    polar polar1{ 2.0,60.0 };
    rect rect1{ -1.0,1.0 };

    polar* ptr1 = func1(&rect1);
    cout << "distance = " << ptr1->distance << " angle = " << ptr1->angle << endl;
    delete ptr1;

    rect* ptr2 = func2(&polar1);
    cout << "x = " << ptr2->x << " y = " << ptr2->y << endl;
    delete ptr2;

    

    
}

polar* func1(rect* ptr)
{
    polar* ptr1 = new polar;
    (*ptr1).angle = atan2(ptr->y, ptr->x)*180.0/3.14;
    (*ptr1).distance = sqrt(pow(ptr->x,2.0)+pow(ptr->y,2.0));
    return ptr1;
}

rect* func2(polar* ptr)
{
    rect* ptr1 = new rect;
    ptr1->x = (ptr->distance) * cos((ptr->angle)*3.14/180.0);
    ptr1->y = (ptr->distance) * sin((ptr->angle)*3.14/180.0);
    return ptr1;
}

