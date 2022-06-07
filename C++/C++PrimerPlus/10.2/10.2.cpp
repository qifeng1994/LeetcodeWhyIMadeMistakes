#include"Header.h"
#include <iostream>
using namespace std;
int main()
{
    classs cls; //采用了默认的构造函数来初始化数据成员
    cls.add(1, 2);
    cls.show();

    classs cl('b', 0);
    cls.compare(cl);
    return 0;
}
