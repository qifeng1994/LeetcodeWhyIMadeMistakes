//ָ�����

#include <iostream>
using namespace std;

//������
class A
{
public:
    int data1;
    A(int a);
    void show();
};

//������
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
    A A1(1); //�ù��캯��ʵ����һ������
    A1.show();

    //Ҫô��ʵ����һ������Ȼ����ָ��ָ����
    A* ptr1 = &A1; //ָ��ָ��һ������
    cout << "use ptr1 to show : ";
    ptr1->show();

    //Ҫô����ָ��ָ��һ��new����Ȼ���ٰ�����ת�Ƹ�ʵ��
    A* ptr2 = new A ( 2 ); 
    cout << "use ptr2 to show : ";
    ptr2->show();
    A A3 = *ptr2; //��ָ������ݸ�ֵ��һ������


    return 0;
}