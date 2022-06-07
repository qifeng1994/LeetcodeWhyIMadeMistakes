//����ģ��,���廯,ʵ����
//���廯�����ڳ���ģ��
#include <iostream>
using namespace std;

template <typename T>
void func(T& a, T& b);

struct str
{
	int data1;
};

template <> 
void func<str>(str& a, str& b); //ע����廯��д��

int main()
{
	int a = 1, b = 2;
	char c = 'c', d = 'd';
	func(a, b);
	func(c, d);
	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;

	str str1{ 1 };
	str str2 = { 2 };
	func(str1, str2);
	cout << "str1 = " << str1.data1 << " str2 = " << str2.data1 << endl;

	return 0;
}

template<typename T>
void func(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> 
void func<str>(str& a, str& b)
{
	int temp;
	temp = a.data1;
	a.data1 = b.data1;
	b.data1 = temp;
}