//������Ҫ���ڽṹ����
#include <iostream>
using namespace std;
struct str
{
    int data1;
    int data2;
};
void func1(const str& re); //const�޷����޸�
void func2(str& re);
str& func3(str& re1, const str& re2); //��������Ϊ����

int main()
{
    str str1{ 1,2 };
    str str2{ 1,2 };
    func1(str1);
    func2(str2);
    str str3 = func3(str1, str2);
    cout << "data1 = " << str3.data1 << " data2 = " << str3.data2 << endl;
    return 0;
}

void func1(const str& re)
{
    cout << "data1 = " << re.data1  << " data2 = " << re.data2  << endl;
}

void func2(str& re)
{
    cout << "data1 = " << ++ re.data1  << " data2 = " << ++ re.data2  << endl; //ԭֵ���޸�
}

str& func3(str& re1, const str& re2)
{
    re1.data1 += re2.data1;
    re1.data2 += re2.data2;
    return re1;
}