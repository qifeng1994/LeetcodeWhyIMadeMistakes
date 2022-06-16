#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

//�º����������嵥16.15
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

	yadayada.remove_if(f100); //���������
	etcetera.remove_if(TooBig<int>(200)); //������������

	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
}

//�����嵥16.18
void test_list()
{
	const int LIM = 10;
	int ar[LIM]{ 4,5,4,2,2,3,4,8,1,4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);

	cout << "original list contents: \n";
	for_each(la.begin(), la.end(), outint);
	cout << endl;

	//�Ƴ�4��ֻʣ6��Ԫ��
	//std::list<T,Allocator>::remove
	//void remove( const T& value )
	la.remove(4);
	cout << "after using remove() method: \n";
	for_each(la.begin(), la.end(), outint);
	cout << endl;

	//����10��Ԫ�أ���������Ч��Ԫ��
	//std::remove
	//template< class ForwardIt, class T >
	//ForwardIt remove(ForwardIt first, ForwardIt last, const T & value);
	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4); //���remove()���ǳ�Ա��������˲��ܵ�������ĳ��ȣ�����û��ɾ����Ԫ�ط�������Ŀ�ʼλ�ã�����ָ���µĳ�βֵ�ĵ��������������дauto�Ļ���򵥵�
	cout << "after using remove() function: \n";
	for_each(lb.begin(), lb.end(), outint);
	cout << endl;

	//ɾ������Ҫ������
	lb.erase(last, lb.end());
	cout << "after using eraser() method: \n";
	for_each(lb.begin(), lb.end(), outint);
	cout << endl;
}
