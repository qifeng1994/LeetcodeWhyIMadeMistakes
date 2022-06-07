//字符串和数组的总结
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	//4.2
	//char c_array[] = "this array store char"; //初始化一个字符串类型的数组，也就是说数组中储存的是字符
	//cout << "length of this array is " << strlen(c_array)<<endl; //strlen()是一个C库函数

	//4.3 cin的局限性,cin遇到空格或者回车就会暂停读取,并把回车留在队列中
	//char c_name[20];
	//cout << "enter you name with space" << endl;
	//cin >> c_name;
	//cout << "the full name is " << c_name << endl; 

	//4.4 cin.genline的用法,读取指定数目的字符，或遇到换行符后停止读取。把换行符替换成空字符\0保存到数组中。也就是说这种方法只能保存N-1个字符
	//char cc_name[4];
	//cout << "enter you name feng" << endl;
	//cin.getline(cc_name, 4);
	//cout << "the name is " << cc_name << endl;

	//4.5 cin.get()的用法，把换行符留在队列中
	//char ccc_name[5];
	//cout << "enter your name feng" << endl;
	//cin.get(ccc_name,5); //同样只能读取N-1个字符
	//cout << "the name is " << ccc_name << endl;
	//cout << "enter you name qi" << endl;
	//cin.get(ccc_name, 5); //队列中剩一个换行符
	//cout << "the name is " << ccc_name << endl;

	//4.5 cin.get()可以单独读取一个换行符
	//char cccc_name[5];
	//cout << "enter your name feng" << endl;
	//cin.get(cccc_name, 5);
	//cin.get();
	//cout << "the name is " << cccc_name << endl;
	//cout << "enter you name qi" << endl;
	//cin.get(cccc_name, 5).get(); 
	//cout << "the name is " << cccc_name << endl;

	//4.9 cstring库函数
	char charr1[]{ "feng" };
	char charr2[]{ "qi" };
	cout << "copy charr2 to charr1 : " << strcpy(charr1, charr2)<<endl;
	cout << "cat charr2 to charr1 : " << strcat(charr1, charr2) << endl;

	return 0;
}