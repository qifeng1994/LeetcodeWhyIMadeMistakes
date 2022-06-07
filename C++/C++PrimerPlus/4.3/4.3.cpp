//string类的总结
#include<iostream>
#include<string>

using namespace std;
int main()
{
	//4.10
	string str;
	cout << "enter your name" << endl; 
	getline(cin, str); //getline()是istream的类方法
	cout << "the name is : " << str << endl;

	return 0;
}