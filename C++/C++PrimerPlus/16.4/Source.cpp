#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

void test_iterator() //程序清单16.10
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

	//rbegin() rend()返回一个反向迭代器，对它进行递增操作将导致它递减
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ",";
	cout << endl;
}

#include <string>
#include <algorithm>
//程序清单16.11
void output(const string& s) { cout << s << ","; }
void test_insert()
{
	string s1[4] = { "fine","fish","fashion","food" };
	string s2[2] = { "busy","bats" };
	string s3[2] = { "silly","singers" };

	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;
	//为名为words的vector<string>容器创建插入迭代器
	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;
	//创建插入迭代器，并指定要从头部插入
	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
	for_each(words.begin(), words.end(), output);
	cout << endl;

}

#include <list>
//程序清单16.12
void outint(int n) { cout << n << ","; }
void test_list()
{
	list<int> one(5, 2); //2 2 2 2 2
	int stuff[5] = { 1,2,4,8,6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5); // 1 2 4 8 6
	list<int> three(two);
	int more[6] = { 6,4,2,4,6,5 };
	three.insert(three.end(), more, more + 6); // 1 2 4 8 6 6 4 2 4 6 5

	three.remove(2); //移除是2的元素
	three.splice(three.begin(), one); //将链表x的内容插入到three.begin()前面
	three.unique(); //将连续相同的元素压缩为单个元素
	three.sort(); //按照<运算符排序
	three.unique();
	two.sort();
	three.merge(two); //将链表two与three合并，前提两个链表必须已经排序，合并后的经过排序的链表保存在three中

	for_each(three.begin(), three.end(), outint);
}

#include <set>
//程序清单16.13
void test_set()
{
	const int N = 6;
	string s1[N]{ "buffoon","thinkers","for","heavy","can","for" };
	string s2[N] = { "metal","any","food","elegant","deliver","for" };
	//关联容器会自动排序
	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);

	for_each(A.begin(), A.end(), output); //set容器中不能有相同的键值
	cout << endl;
	ostream_iterator<string, char> out(cout, ","); //声明一个输出迭代器
	set_union(A.begin(), A.end(), B.begin(), B.end(), out); //并集
	cout << endl;
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out); //交集
	cout << endl;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out); //集合的差：第一个集合减去交集
	cout << endl;

	set<string> C;
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C,C.begin())); //取并集后插入
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3{ "grungy" };
	C.insert(s3);
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out); //在这两个区间的元素
	cout << endl;
}

#include <map>
//程序清单16.14
void test_multimap() //一个键可以有多个值
{
	typedef int KeyType;
	typedef pair<const KeyType, string> Pair;
	typedef multimap<KeyType, string> MapCode;

	MapCode codes;
	codes.insert(Pair(415, "san fran"));
	codes.insert(Pair(718, "brooklyn"));
	codes.insert(Pair(510, "oakland"));
	codes.insert(Pair(718, "staten"));
	codes.insert(Pair(415, "san ra"));
	codes.insert(Pair(510, "berke"));

	cout << "num of cities with area code 415: " << codes.count(415) << endl; //返回键415对应的值的个数
	MapCode::iterator it; //为什么要这样获取迭代器？？
	for (it = codes.begin(); it != codes.end(); ++it)
		cout << " " << (*it).first << " " << (*it).second << endl; //采用新的for range写法能实现吗？？
	
	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718); //equal_range返回两个迭代器，将它们封装在pair对象中 这里写auto应该可以
	cout << "cities with area code 718: \n";
	for (it = range.first; it != range.second; ++it)
		cout << " " << (*it).first << " " << (*it).second << endl;
}
int main()
{
	// test_iterator();
	// test_insert();
	// test_list();
	// test_set();
	test_multimap();
	return 0;
}