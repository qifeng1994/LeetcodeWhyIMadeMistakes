#include<iostream>
#include<string>

using namespace std;

//程序清单18.10 这种写法算重载么
void show_list() {} //拆包最后是空包的情况

template<typename T>
void show_list(const T& value) //拆包拆到只剩一个元素的情况，这样最后一个元素就不会有逗号
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
