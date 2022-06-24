#include <iostream>
#include <string>
using namespace std;

void test_compare_function()
{
	//compare()如果比较结果相同返回0，否则返回非0 能区分大小写
    string A("aBcdef");
    string B("AbcdEf");
    string C("123456");
    string D("123dfg");
    //下面是各种比较方法
    int m = A.compare(B); //完整的A和B的比较
    int n = A.compare(1, 5, B); //"Bcdef"和"AbcdEf"比较
    int p = A.compare(1, 5, B, 4, 2); //"Bcdef"和"Ef"比较
    int q = C.compare(0, 3, D, 0, 3); //"123"和"123"比较
    cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl;

    //重载运算符比较的是字符串的大小，按照字母顺序排序
    string S1 = "DEF";
    string CP1 = "ABC";
    cout << "S1= " << S1 << endl;
    cout << "CP1 = " << CP1 << endl;
    cout << "S1 <= CP1 returned " << (S1 <= CP1) << endl; //return 0

}

void test_update_function()
{
    //assign()
    string str1("123456");
    string str;
    str.assign(str1); cout << str << endl; //直接赋值    
    str.assign(str1, 3, 3); cout << str << endl; //456  
    str.assign(str1, 2, str1.npos); cout << str << endl; //赋值给从位置 2 至末尾的子串 3456    
    str.assign(5, 'X'); cout << str << endl; //重复 5 个'X'字符
}

void test_find_function()
{
    //find_first_of()
    string str_ch("for");
    string str("Hi, Pete, I'm sick. Please bought some drugs for me. ");
    string::size_type n = str.find_first_of("some", 0); //在str中从0查找第一次出现some中的字符的位置
    cout << "Example - find_first_of(): The position (forward) of 'some' is: " << (int)n << endl;
    string::size_type mo = str.find_first_of("drugs", 0, 3); //在str中从0开始查找，第一次出现dru中的字符的位置
    cout << "Example - find_first_of () : The position (forward) of 'drugs' is: " << (int)mo << endl;
    cout << str[30] << endl;
}

int main()
{
    //test_compare_function();
    //test_update_function();
    test_find_function();
    return 0;
}