//���������
//��Ԫ�����������Թ��� friend
//ת�������������Թ��� operator typeName()
#include <iostream>
#include"Header.h"
using namespace std;

int main()
{
    Time t1{ 30,1 };
    Time t2{ 40,1 };
    t1.operator+(t2);
    t1.show();
    return 0;
}
