#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

//仿函数？程序清单16.15
template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) :cutoff(t) {}
	bool operator()(const T& v) { return v > cutoff; }
};

void outint(int n) { cout << n << " "; }

void test_functor()
{
	TooBig<int> f100(100);
	list<int> yadayada{ 50,100,90,180,60,210,415,88,188,201 };
	list<int> etcetera{ 50,100,90,180,60,210,415,88,188,201 };

	yadayada.remove_if(f100); //运算符重载
	etcetera.remove_if(TooBig<int>(200)); //利用匿名对象

	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
}

//程序清单16.18
void test_list()
{
	const int LIM = 10;
	int ar[LIM]{ 4,5,4,2,2,3,4,8,1,4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);

	cout << "original list contents: \n";
	for_each(la.begin(), la.end(), outint);
	cout << endl;

	//移除4后只剩6个元素
	//std::list<T,Allocator>::remove
	//void remove( const T& value )
	la.remove(4);
	cout << "after using remove() method: \n";
	for_each(la.begin(), la.end(), outint);
	cout << endl;

	//还是10个元素，但是有无效的元素
	//std::remove
	//template< class ForwardIt, class T >
	//ForwardIt remove(ForwardIt first, ForwardIt last, const T & value);
	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4); //这个remove()不是成员函数，因此不能调整链表的长度，它将没被删除的元素放在链表的开始位置，返回指向新的超尾值的迭代器。这里如果写auto的话会简单点
	cout << "after using remove() function: \n";
	for_each(lb.begin(), lb.end(), outint);
	cout << endl;

	//删除不需要的区间
	lb.erase(last, lb.end());
	cout << "after using eraser() method: \n";
	for_each(lb.begin(), lb.end(), outint);
	cout << endl;
}
