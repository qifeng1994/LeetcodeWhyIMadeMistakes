#include"Header.h"
#include <iostream>
using namespace std;
int main()
{
    classs cls; //������Ĭ�ϵĹ��캯������ʼ�����ݳ�Ա
    cls.add(1, 2);
    cls.show();

    classs cl('b', 0);
    cls.compare(cl);
    return 0;
}
