//ָ����ַ���
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
    char* ptr = new char[6]; //���һλ��\0
	for (int i = 0; i < 5; i++)
	{
		ptr[i] = 'q';
	}
	ptr[5] = '\0'; //�����仰û�еĻ������ӡ�����߰���Ķ���
	return ptr;
}

