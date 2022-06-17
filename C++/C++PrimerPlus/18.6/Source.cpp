#include<iostream>
#include<string>

using namespace std;

//�����嵥18.10 ����д��������ô
void show_list() {} //�������ǿհ������

template<typename T>
void show_list(const T& value) //�����ֻʣһ��Ԫ�ص�������������һ��Ԫ�ؾͲ����ж���
{
	cout << value << '\n';
}

template<typename T, typename...Args>
void show_list(const T& t, Args&... args)
{
	cout << t << ",";
	show_list(args...);
}

int main()
{
	int n = 10;
	double x = 2.1;
	string st = "hello";
	show_list(n * n, x, st);
	return 0;
}
