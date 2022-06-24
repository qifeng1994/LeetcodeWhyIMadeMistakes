//代码来自侯捷老师关于STL教学的PPT
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define ASIZE 100000

namespace p2_STL
{
	//p2 intro STL
	//STL的六大组件，container,allocator 分配器,algorithms,iterator 迭代器,adapter 适配器,functor 仿函数 
	void p2_stl_example() //利用stl六大组件的例子
	{
		int i[6] = { 27,210,12,47,109,83 };
		vector<int, allocator<int>> vi(i, i + 6); //allocator为int类型的vector分配内存，也可以省略不写
		//count_if是一个算法，begin end都返回一个迭代器，bind2nd是一个适配器 限定了第二个参数是40，not1取反也是一个适配器，less是一个仿函数 实现了小于的功能
		//这句话的意思是，查找int数组i，打印出大于40的数字的个数
		cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));
	}
	//复杂度相关
	//range-based for statement (since C++11) for循环的新写法
	void p2_stl_loop()
	{
		vector<int> vec{ 1,2,3,4,5,6 };
		for (auto elem : vec) { cout << elem << endl; }
		for (auto& elem : vec) { elem *= 3; } //改变了原值
		for (auto elem : vec) { cout << elem << endl; }
	}
}

//测试用函数
long get_a_target_long() //让测试者输入一个数字
{
	long target = 0;
	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

string get_a_target_string()
{
	long target = 0;
	char buf[10];
	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target); //把target转换成字符串
	return string(buf);
}

int compareLongs(const void* a, const void* b) //比较两个数大小，这里为什么是void* ??
{
	return (*(long*)a - *(long*)b);
}

int compareStrings(const void* a, const void* b) //比较两个字符串的长度
{
	if (*(string*)a > *(string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return - 1;
	else
		return 0;
}

#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib> //qsort,bsearch,NULL
namespace p3_array //array是内存连续的，长度固定的数据类型
{
	//p3 about container
	//sequence containers :array, vector, deque, list 双向链表, forward list单向链表 
	//associative containers: set/multiset 红黑树, map/multimap 红黑树 数据是键值对
	//hash table separate chaining

	//array example
	void test_array()
	{
		cout << "\ntest_array()......\n";
		array<long, ASIZE> c;
		clock_t timeStart = clock(); //程序执行到这里花的时间
		for (long i=0;i<ASIZE;++i)
		{
			c[i] = rand();
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl; //执行for-loop花费了多少时间
		cout << "array.size()= " << c.size() << endl; //有多少个数据
		cout << "array.front()= " << c.front() << endl;
		cout << "array.back()= " << c.back() << endl;
		cout << "array.data= " << c.data() << endl; //这个数组的起点在内存中的地址

		long target = get_a_target_long();
		timeStart = clock();
		qsort(c.data(), ASIZE, sizeof(long), compareLongs); //快速排序方法
		long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs); //二分查找法
		cout << "qsort()+bsearch(), milli-seconds : " << (clock() - timeStart) << endl; //排序+查找所花的时间
		if (pItem != NULL)
			cout << "found, " << *pItem << endl;
		else
			cout << "not found!" << endl;
	}
}

#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio> //snprintf()
#include <iostream>
#include <ctime>
#include <algorithm> //sort()
namespace p4_vector //vector是内存连续的，一端开口的数据类型
{
	void test_vector(long& value)
	{
		cout << "\ntest_vector()........\n";
		vector<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i)
		{
			try
			{
				snprintf(buf, 10, "%d", rand()); //把数字转为字符串
				c.push_back(string(buf));
			}
			catch (exception& p) //内存不够发生异常
			{
				cout << "i=" << " " << p.what() << endl;
				abort(); //退出程序
			}
		}
		cout << "milli-second : " << (clock() - timeStart) << endl;
		cout << "vector.size()= " << c.size() << endl;
		cout << "vector.front()= " << c.front() << endl;
		cout << "vector.back()= " << c.back() << endl;
		cout << "vector.capacity()= " << c.capacity() << endl; //vector实际的大小

		//这里还有一段查找排序的程序略过了没写
	}
}

#include <list>
namespace p5_list //list的内存不连续，双向链表
{
	void test_list(long& value)
	{
		cout << "\ntest_list().......\n";
		list<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i=0;i<value;++i)
		{
			try
			{
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (const std::exception&)
			{
				//
				abort();
			}
		}

		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "list.size()= " << c.size() << endl;
		cout << "list.max_size()= " << c.max_size() << endl; //返回可容纳的最大元素数
		//省略部分代码

	}
}

#include<forward_list>

namespace p5_forward_list //单向链表 
{
	//插入数据用push_front()方法
}

namespace p5_deque //双端队列，内存是分段连续buffer，数据两端开口
{

}

//p6 关联式容器查找非常快 这种数据类型在插入之后都是自动排列好的么？？？

namespace p6_multiset //接受重复的数据，数据表现为红黑树
{
	//插入数据用insert()方法
}

namespace p6_multimap //接受重复的数据，数据表现为红黑树
{
	//insert(pair<keytype,valuetype>(key,value))
}

namespace p6_unordered_multiset //数据表现为hash table
{
	//insert()
	//bucket_count() bucket_size()是特有的方法
}

namespace p6_set //插入重复的数据视为无效
{

}

namespace p6_map //如果插入两个相同key但是不同value的数据会怎么样???
{
	//赋值方式 mapname[key]=value
}


//p7 allocator 分配器，用于分配内存，略过




//P8标准库源码位置，gnu4.9.2\include\c++\bits\stl_xxx

//P9容器的数据在使用方法的时候，是通过迭代器来实现算法

//P11 在VC6，GCC2.9的标准库中，allocators分配器，通过调用operator new()去实现分配内存，而operator new()最终调用的是malloc()，导致over head开销大
//GCC2.9中实际用的分配器叫alloc在<stl_alloc.h>中，
//GCC4.9中使用回到了VC6的分配器，原来现在GCC都已经到22版本了

//p13
