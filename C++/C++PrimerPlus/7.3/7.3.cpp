//ָ���const
#include <iostream>
using namespace std;
int main()
{
	int data1 = 1, data2 = 2;
	const int* ptr1 = &data1; //����ͨ��ָ���޸�ԭֵ,��������ָ����������
	cout << "data1 + 1 = " << data1+1 << endl;
	ptr1 = &data2;
	cout << "data2 = " << *ptr1 << endl;

	int* const ptr2 = &data1; //����ָ����������������ͨ��ָ���޸�ԭֵ
	cout << "data1 + 1 = " << *ptr2 + 1 << endl;
	
}