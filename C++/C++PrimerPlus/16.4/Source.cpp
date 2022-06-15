#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

void test_iterator()
{
	//将copy作用于数组，第三个参数表示复制的起始位置
	int casts[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>dice(10); //这里如果没有指定大小，后面执行的时候会报错
	copy(casts, casts + 10, dice.begin());

	//输出迭代器，这里表示把int输出为char类型
	ostream_iterator<int, char>out_iter(cout, ",");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;

	//反向输出
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;

	//反向迭代器
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