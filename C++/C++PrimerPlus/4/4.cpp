//�ַ�����������ܽ�
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	//4.2
	//char c_array[] = "this array store char"; //��ʼ��һ���ַ������͵����飬Ҳ����˵�����д�������ַ�
	//cout << "length of this array is " << strlen(c_array)<<endl; //strlen()��һ��C�⺯��

	//4.3 cin�ľ�����,cin�����ո���߻س��ͻ���ͣ��ȡ,���ѻس����ڶ�����
	//char c_name[20];
	//cout << "enter you name with space" << endl;
	//cin >> c_name;
	//cout << "the full name is " << c_name << endl; 

	//4.4 cin.genline���÷�,��ȡָ����Ŀ���ַ������������з���ֹͣ��ȡ���ѻ��з��滻�ɿ��ַ�\0���浽�����С�Ҳ����˵���ַ���ֻ�ܱ���N-1���ַ�
	//char cc_name[4];
	//cout << "enter you name feng" << endl;
	//cin.getline(cc_name, 4);
	//cout << "the name is " << cc_name << endl;

	//4.5 cin.get()���÷����ѻ��з����ڶ�����
	//char ccc_name[5];
	//cout << "enter your name feng" << endl;
	//cin.get(ccc_name,5); //ͬ��ֻ�ܶ�ȡN-1���ַ�
	//cout << "the name is " << ccc_name << endl;
	//cout << "enter you name qi" << endl;
	//cin.get(ccc_name, 5); //������ʣһ�����з�
	//cout << "the name is " << ccc_name << endl;

	//4.5 cin.get()���Ե�����ȡһ�����з�
	//char cccc_name[5];
	//cout << "enter your name feng" << endl;
	//cin.get(cccc_name, 5);
	//cin.get();
	//cout << "the name is " << cccc_name << endl;
	//cout << "enter you name qi" << endl;
	//cin.get(cccc_name, 5).get(); 
	//cout << "the name is " << cccc_name << endl;

	//4.9 cstring�⺯��
	char charr1[]{ "feng" };
	char charr2[]{ "qi" };
	cout << "copy charr2 to charr1 : " << strcpy(charr1, charr2)<<endl;
	cout << "cat charr2 to charr1 : " << strcat(charr1, charr2) << endl;

	return 0;
}