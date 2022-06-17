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

void test_lambda() //程序清单18.4和18.5 统计一组随机数中能被3整除的元素个数
{
	vector<int>numbers(size1);
	// srand(time(0)); //这句话不知道是干什么的，没有好像也没有关系
	generate(numbers.begin(), numbers.end(), rand);

	//利用函数指针
	cout << "sample size = " << size1 << '\n';
	int count3 = count_if(numbers.begin(), numbers.end(), f3);
	cout << "可以被3整除的元素个数是：" << count3 << endl;

	//利用仿函数
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
	cout << "可以被3整除的元素个数是：" << count3 << endl;

	//利用lambda表达式
	numbers.resize(size3);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "sample size = " << size3 << '\n';

	count3 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
	cout << "可以被3整除的元素个数是：" << count3 << endl;

	count3 = 0;
	for_each(numbers.begin(), numbers.end(), [&count3](int x) {count3 += x % 3 == 0; }); //[&count3]表示按引用访问变量
	cout << "可以被3整除的元素个数是：" << count3 << endl;

	int count13 = count3 = 0;
	for_each(numbers.begin(), numbers.end(), [&](int x) {count3 += x % 3 == 0; count13 += x % 13 == 0; }); //[&]表示能按引用访问所有动态变量
	cout << "可以被3整除的元素个数是：" << count3 << endl;
	cout << "可以被13整除的元素个数是：" << count13 << endl;

}

int main()
{
	test_lambda();
	return 0;
}