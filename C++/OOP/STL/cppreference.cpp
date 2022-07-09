//记录一些来自cppreference.com的说明
#include <iostream>
using namespace std;

namespace language
{
	#if 0
		std::cout << "这一句不会被执行，甚至不会被编译\n";
	#endif

	void ascii_()
	{
		char i = 65; //A
		cout << "打印ASCII表中编号为" << int(i) << "的字符:" << i;
	}

	void sizeof_()
	{
		struct BaseData { int a; };
		BaseData bd;
		cout << "sizeof运算符用于查询对象或类型的大小" << endl;
		cout << "通过类型查询: sizeof(BaseData) = " << sizeof(BaseData) << endl;
		cout << "通过表达式查询: sizeof bd = " << sizeof bd << endl;
	}
}

#include <array>
#include <vector>
#include <algorithm>
namespace container
{
	void test_array()
	{
		array<int, 5>a{ 4,5,1,3,2 };

		cout << "array a 的默认值是：";
		for (const int& i : a)
			cout << i << ", ";
		cout << '\n';

		sort(a.begin(), a.end());
		cout << "经过sort之后的array是：";
		for (const int& i : a)
			cout << i << ", ";
		cout << '\n';

		//元素访问
		cout << "利用at访问第一个元素a[0]=" << a.at(0) << ", ";
		a.at(0) = 6;
		cout << "利用at修改第一个元素后，a[0]=" << a.at(0) << endl;
		cout << "利用front访问第一个元素 = " << a.front() << ", 利用back访问最后一个元素 = " << a.back() << endl;
		auto p = a.data();
		cout <<"data()返回数组的指针p，默认指向第一个元素，那么第二个元素的值就是* (p + 1)="<< * (p + 1) << endl;

		//迭代器
		cout << "begin()返回指向起始的迭代器，那么*(a.begin())表示第一个元素的值：" << *(a.begin()) << "，但是end()指向最后一个元素的下一位，因此不能解引用" << endl;

		//TODO:rbegin() rend()

		//容量
		cout << "size()返回容纳的元素数" << a.size() << endl;
		cout << "max_size()返回可容纳的最大元素数，由于array的容量是固定的，因此跟上一行相等" << a.max_size() << endl;
		cout << "empty()检查容器是否为空：" << a.empty() << endl;

		//操作
		array<int, 5> aa{ 5,7,8,9,10 };
		a.swap(aa);
		cout << "利用swap()交换后，array a的元素是：";
		for (const int& i : a)
			cout << i << ", ";
		cout << '\n';
		//TODO:fill()
	}

	void test_vector()
	{
		//构造函数
		vector<string> v1{ "a1","b2","c3"}; //初始化
		vector<string> v2(3, "d4"); //(3)构造函数
		for (auto& e : v2) { cout << e <<","; } cout << endl;

		//容量 empty size
		cout << "size()返回容纳的元素数=" << v1.size() << ",max_size()返回可容纳的最大元素数=" << v1.max_size() << endl;
		cout << "capacity()返回当前存储空间能容纳的元素数=" << v1.capacity() << endl;
		//TODO:reserve shrink_to_fit

		//修改器
		cout << "insert()有很多用法，大多利用迭代器实现灵活的插入" << endl;
		v1.push_back("e5");
		v1.pop_back();
		v1.erase(v1.begin());
	}
}

namespace algor
{
	//修改序列的操作
	//TODO:all_of,for_each,find_if
	void count_()
	{
		vector<int> v{ 1,2,2,2 };
		int num = count(v.begin(), v.end(), 2);
		cout << "vector v 中有 " << num << " 个数字2" << endl;
	}

	void mismatch_()
	{
		vector<string> v1{ "a","b","c","d" };
		vector<string> v2{ "a","b","c","e" };
		auto pa = mismatch(v1.begin(), v1.end(), v2.begin());
		cout <<"mismatch()指向首二个不相等元素的迭代器 " << *pa.first << " " << *pa.second << endl;
		//官方案例还有很多精妙的写法
	}

	void find_end_()
	{
		vector<int> v1{ 1,2,3,4,1,2,3,4,5 };
		vector<int> v2{ 1,2,3 };
		vector<int>::iterator result;
		result = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
		cout << "find_end()返回在v1中最后一次出现v2的起始的迭代器 指向v1中的第 " <<distance(v1.begin(),result)+1<<" 个元素 " << *result << endl;
	}

	void find_first_of_()
	{
		vector<int> v1{ 0,1,2,3,4,5 };
		vector<int> v2{ 6,7,3,2 };
		auto result = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
		cout <<"find_first_of()返回在v1中首次出现v2中含有的元素的迭代器 首次出现的元素是 " << *result << endl;
	}

	void adjacent_find_()
	{
		vector<int> v1{ 0,1,2,3,40,40,41,41,5 };
		auto i1 = adjacent_find(v1.begin(), v1.end()); //返回迭代器
		cout << "adjacent_find()搜索范围中两个相继相等的元素, v1中首个相等的元素是 第" << distance(v1.begin(),i1)<<"个，元素是 " <<*i1<< endl;

		//TODO
		cout << "adjacent_find()还可以基于条件判断" << endl;
	}

	void search_()
	{
		string str = "why waste time learning, when ignorance is instantaneous?";
		string substr = "learning";
		auto result = search(str.begin(), str.end(), substr.begin(), substr.end());
		cout << "search()搜索范围中首次出现某个子序列，str中首个相等的子序列是 第" << distance(str.begin(),result)<<"个，元素是 " << *result << endl;
	}
}

//int main()
//{
//	algor::search_();
//	return 0;
//}

//c11新特性：lambda表达式