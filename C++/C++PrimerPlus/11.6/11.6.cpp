
#include "Header.h"
#include <iostream>
using namespace std;
int main()
{
    //�����ʼ���ķ�ʽ
    Stone stn1 = 15.0; //ʵ�����ù��캯���Գ�Ա���ݽ����˳�ʼ��������д��û��ֱ�ӵ��ú���������Ϊ��ʽת��
    stn1.show_pounds();
    stn1.show_stone();

    Stone stn2 = Stone(16); //��ʽǿ������ת��
    Stone stn3(1, 1);
    stn3.show_pounds();
    
    //ת��������ʹ��
    Stone stn4(1, 1.6); //��ν��ʼ������������һ�̾�����ʹ�õ����ĸ����캯������Ա������ʲô
    double cov_double = stn4;  
    cout << "convert to double = " << cov_double << " pounds.\n";
    cout << "convert to int = " << int(stn4) << " pounds.\n";
    return 0;
}
