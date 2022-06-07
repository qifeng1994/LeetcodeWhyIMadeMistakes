//指针和字符串
#include <iostream>
using namespace std;

char* func();

int main()
{
	char* pt = func();
	cout << pt << endl;
	delete[]pt;

	return 0;
}

char* func()
{
    char* ptr = new char[6]; //最后一位是\0
	for (int i = 0; i < 5; i++)
	{
		ptr[i] = 'q';
	}
	ptr[5] = '\0'; //如果这句话没有的话，会打印出乱七八糟的东西
	return ptr;
}

