#include<iostream>
#include"Header.h"

using namespace std;

Time::Time()
{
	min = hour = 0;
}

Time::Time(int m, int h)
{
	min = m;
	hour = h;
}

Time Time :: operator+(Time& t) //ע�������д������һ��time�Ƿ������� �ڶ���time������
{
	min += t.min;
	hour = hour + t.hour + (min / 60);
	min = min % 60;
	return *this;
}

void Time::show()
{
	cout << "hour : " << hour << " minute : " << min << endl;
}