//������������
//����virtual�����鷽��ʵ�ֶ�̬
#include"Header.h"
#include <iostream>
using namespace std;
int main()
{
    BaseClass bc ( 1,2 );
    DerivedClass* dc = new DerivedClass(3, bc); //����ָ�벢��ʼ��
    DerivedClass ddc( 4,bc );
    BaseClass* ptr = &ddc; //����ָ��

    bc.show();
    dc->show(); //�������Լ����鷽��
    dc->BaseClass::show(); //ͨ��ָ�������������ø�����鷽��
    ddc.BaseClass::show(); //ֱ�ӷ��ʸ����鷽��
    ptr->show(); //���ָ�����ָ���࣬��ôҲһ������ָ������,������õ�������show����
    return 0;
}
