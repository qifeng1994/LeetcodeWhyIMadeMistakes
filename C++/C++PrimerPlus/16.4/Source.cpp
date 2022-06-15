#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

void test_iterator()
{
	//��copy���������飬������������ʾ���Ƶ���ʼλ��
	int casts[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>dice(10); //�������û��ָ����С������ִ�е�ʱ��ᱨ��
	copy(casts, casts + 10, dice.begin());

	//����������������ʾ��int���Ϊchar����
	ostream_iterator<int, char>out_iter(cout, ",");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;

	//�������
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;

	//���������
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ",";
	cout << endl;
}

int main()
{
	test_iterator();
	return 0;
}