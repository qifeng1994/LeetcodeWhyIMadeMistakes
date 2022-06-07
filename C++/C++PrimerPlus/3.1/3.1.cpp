#include <iostream>
#include<climits>
using namespace std;

int main()
{
	
	//using climits
	int m_int = INT_MAX; //有符号
	unsigned int um_int = UINT_MAX; //无符号
	cout << "size of int is " << sizeof m_int << endl;
	cout << "size of int is " << sizeof(int) << endl; //这里注意和上一句用法的区别
	cout << "int max = " << INT_MAX << endl;
	cout << "int max + 1 = " << ++m_int << endl; //数据是一个圆形
	cout << "unsigned int max = " << UINT_MAX << endl;
	cout << "unsigned int max + 1 = " << ++um_int << endl;

	int number_to_15 = 15; //这里的16 是一个十进制数
	cout << hex;
	cout << "change number to 16 : " << number_to_15 << endl; //以十六进制的形式输出

	char ch = 'a';
	int ascii = ch;
	cout << "ascii code of " << ch << " is " << ascii << endl;

	int typechange;
	typechange = 9.9;
	cout << "make 9.9 into a int : " << typechange << endl;
	cout << "or force change type : " << int(9.9) << endl; //强制类型转换




	return 0;
}