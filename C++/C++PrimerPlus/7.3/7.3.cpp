//指针和const
#include <iostream>
using namespace std;
int main()
{
	int data1 = 1, data2 = 2;
	const int* ptr1 = &data1; //不能通过指针修改原值,可以重新指向其他变量
	cout << "data1 + 1 = " << data1+1 << endl;
	ptr1 = &data2;
	cout << "data2 = " << *ptr1 << endl;

	int* const ptr2 = &data1; //不能指向其他变量，可以通过指针修改原值
	cout << "data1 + 1 = " << *ptr2 + 1 << endl;
	
}