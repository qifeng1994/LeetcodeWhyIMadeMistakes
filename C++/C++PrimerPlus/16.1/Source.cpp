#include<iostream>
#include<string>
using namespace std;

//程序清单16.1
void test_string_constructor()
{
	string one("Lottery Winter!");
	string two(10, '$');
	string three(one);
	one += "oops!";
	three[0] = 'p';
	string four;
	four = two + three;

	char alls[] = "abcdefghijklmn";
	string five(alls, 20);
	string six(alls + 6, alls + 10); cout << six << endl;
	string seven(&five[6], &five[10]); cout << seven << endl;
	string eight(five, 6, 10); cout << eight << endl; //从第6位开始，复制10个字符
}

int main()
{
	test_string_constructor();
	return 0;
}