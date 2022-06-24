#include <iostream>
#include <string>
using namespace std;

void test_compare_function()
{
	//compare()����ȽϽ����ͬ����0�����򷵻ط�0 �����ִ�Сд
    string A("aBcdef");
    string B("AbcdEf");
    string C("123456");
    string D("123dfg");
    //�����Ǹ��ֱȽϷ���
    int m = A.compare(B); //������A��B�ıȽ�
    int n = A.compare(1, 5, B); //"Bcdef"��"AbcdEf"�Ƚ�
    int p = A.compare(1, 5, B, 4, 2); //"Bcdef"��"Ef"�Ƚ�
    int q = C.compare(0, 3, D, 0, 3); //"123"��"123"�Ƚ�
    cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl;

    //����������Ƚϵ����ַ����Ĵ�С��������ĸ˳������
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
    str.assign(str1); cout << str << endl; //ֱ�Ӹ�ֵ    
    str.assign(str1, 3, 3); cout << str << endl; //456  
    str.assign(str1, 2, str1.npos); cout << str << endl; //��ֵ����λ�� 2 ��ĩβ���Ӵ� 3456    
    str.assign(5, 'X'); cout << str << endl; //�ظ� 5 ��'X'�ַ�
}

void test_find_function()
{
    //find_first_of()
    string str_ch("for");
    string str("Hi, Pete, I'm sick. Please bought some drugs for me. ");
    string::size_type n = str.find_first_of("some", 0); //��str�д�0���ҵ�һ�γ���some�е��ַ���λ��
    cout << "Example - find_first_of(): The position (forward) of 'some' is: " << (int)n << endl;
    string::size_type mo = str.find_first_of("drugs", 0, 3); //��str�д�0��ʼ���ң���һ�γ���dru�е��ַ���λ��
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