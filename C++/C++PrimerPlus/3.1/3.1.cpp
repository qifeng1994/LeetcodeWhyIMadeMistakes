#include <iostream>
#include<climits>
using namespace std;

int main()
{
	
	//using climits
	int m_int = INT_MAX; //�з���
	unsigned int um_int = UINT_MAX; //�޷���
	cout << "size of int is " << sizeof m_int << endl;
	cout << "size of int is " << sizeof(int) << endl; //����ע�����һ���÷�������
	cout << "int max = " << INT_MAX << endl;
	cout << "int max + 1 = " << ++m_int << endl; //������һ��Բ��
	cout << "unsigned int max = " << UINT_MAX << endl;
	cout << "unsigned int max + 1 = " << ++um_int << endl;

	int number_to_15 = 15; //�����16 ��һ��ʮ������
	cout << hex;
	cout << "change number to 16 : " << number_to_15 << endl; //��ʮ�����Ƶ���ʽ���

	char ch = 'a';
	int ascii = ch;
	cout << "ascii code of " << ch << " is " << ascii << endl;

	int typechange;
	typechange = 9.9;
	cout << "make 9.9 into a int : " << typechange << endl;
	cout << "or force change type : " << int(9.9) << endl; //ǿ������ת��




	return 0;
}