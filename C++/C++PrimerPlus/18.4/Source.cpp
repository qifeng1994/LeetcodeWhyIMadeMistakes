#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>

using namespace std;

const long size1 = 39L;
const long size2 = 100 * size1;
const long size3 = 100 * size2;
bool f3(int x) { return x % 3 == 0; }

void test_lambda() //�����嵥18.4��18.5 ͳ��һ����������ܱ�3������Ԫ�ظ���
{
	vector<int>numbers(size1);
	// srand(time(0)); //��仰��֪���Ǹ�ʲô�ģ�û�к���Ҳû�й�ϵ
	generate(numbers.begin(), numbers.end(), rand);

	//���ú���ָ��
	cout << "sample size = " << size1 << '\n';
	int count3 = count_if(numbers.begin(), numbers.end(), f3);
	cout << "���Ա�3������Ԫ�ظ����ǣ�" << count3 << endl;

	//���÷º���
	numbers.resize(size2);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "sample size = " << size2 << '\n';
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int v = 1) :dv(v) {}
		bool operator()(int x) { return x % dv == 0; }
	};
	count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "���Ա�3������Ԫ�ظ����ǣ�" << count3 << endl;

	//����lambda���ʽ
	numbers.resize(size3);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "sample size = " << size3 << '\n';

	count3 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
	cout << "���Ա�3������Ԫ�ظ����ǣ�" << count3 << endl;

	count3 = 0;
	for_each(numbers.begin(), numbers.end(), [&count3](int x) {count3 += x % 3 == 0; }); //[&count3]��ʾ�����÷��ʱ���
	cout << "���Ա�3������Ԫ�ظ����ǣ�" << count3 << endl;

	int count13 = count3 = 0;
	for_each(numbers.begin(), numbers.end(), [&](int x) {count3 += x % 3 == 0; count13 += x % 13 == 0; }); //[&]��ʾ�ܰ����÷������ж�̬����
	cout << "���Ա�3������Ԫ�ظ����ǣ�" << count3 << endl;
	cout << "���Ա�13������Ԫ�ظ����ǣ�" << count13 << endl;

}

int main()
{
	test_lambda();
	return 0;
}