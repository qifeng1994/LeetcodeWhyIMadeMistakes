//string����ܽ�
#include<iostream>
#include<string>

using namespace std;
int main()
{
	//4.10
	string str;
	cout << "enter your name" << endl; 
	getline(cin, str); //getline()��istream���෽��
	cout << "the name is : " << str << endl;

	return 0;
}