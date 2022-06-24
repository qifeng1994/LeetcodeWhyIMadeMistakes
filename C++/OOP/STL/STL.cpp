//�������Ժ����ʦ����STL��ѧ��PPT
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define ASIZE 100000

namespace p2_STL
{
	//p2 intro STL
	//STL�����������container,allocator ������,algorithms,iterator ������,adapter ������,functor �º��� 
	void p2_stl_example() //����stl�������������
	{
		int i[6] = { 27,210,12,47,109,83 };
		vector<int, allocator<int>> vi(i, i + 6); //allocatorΪint���͵�vector�����ڴ棬Ҳ����ʡ�Բ�д
		//count_if��һ���㷨��begin end������һ����������bind2nd��һ�������� �޶��˵ڶ���������40��not1ȡ��Ҳ��һ����������less��һ���º��� ʵ����С�ڵĹ���
		//��仰����˼�ǣ�����int����i����ӡ������40�����ֵĸ���
		cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));
	}
	//���Ӷ����
	//range-based for statement (since C++11) forѭ������д��
	void p2_stl_loop()
	{
		vector<int> vec{ 1,2,3,4,5,6 };
		for (auto elem : vec) { cout << elem << endl; }
		for (auto& elem : vec) { elem *= 3; } //�ı���ԭֵ
		for (auto elem : vec) { cout << elem << endl; }
	}
}

//�����ú���
long get_a_target_long() //�ò���������һ������
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
	snprintf(buf, 10, "%d", target); //��targetת�����ַ���
	return string(buf);
}

int compareLongs(const void* a, const void* b) //�Ƚ���������С������Ϊʲô��void* ??
{
	return (*(long*)a - *(long*)b);
}

int compareStrings(const void* a, const void* b) //�Ƚ������ַ����ĳ���
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
namespace p3_array //array���ڴ������ģ����ȹ̶�����������
{
	//p3 about container
	//sequence containers :array, vector, deque, list ˫������, forward list�������� 
	//associative containers: set/multiset �����, map/multimap ����� �����Ǽ�ֵ��
	//hash table separate chaining

	//array example
	void test_array()
	{
		cout << "\ntest_array()......\n";
		array<long, ASIZE> c;
		clock_t timeStart = clock(); //����ִ�е����ﻨ��ʱ��
		for (long i=0;i<ASIZE;++i)
		{
			c[i] = rand();
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl; //ִ��for-loop�����˶���ʱ��
		cout << "array.size()= " << c.size() << endl; //�ж��ٸ�����
		cout << "array.front()= " << c.front() << endl;
		cout << "array.back()= " << c.back() << endl;
		cout << "array.data= " << c.data() << endl; //��������������ڴ��еĵ�ַ

		long target = get_a_target_long();
		timeStart = clock();
		qsort(c.data(), ASIZE, sizeof(long), compareLongs); //�������򷽷�
		long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs); //���ֲ��ҷ�
		cout << "qsort()+bsearch(), milli-seconds : " << (clock() - timeStart) << endl; //����+����������ʱ��
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
namespace p4_vector //vector���ڴ������ģ�һ�˿��ڵ���������
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
				snprintf(buf, 10, "%d", rand()); //������תΪ�ַ���
				c.push_back(string(buf));
			}
			catch (exception& p) //�ڴ治�������쳣
			{
				cout << "i=" << " " << p.what() << endl;
				abort(); //�˳�����
			}
		}
		cout << "milli-second : " << (clock() - timeStart) << endl;
		cout << "vector.size()= " << c.size() << endl;
		cout << "vector.front()= " << c.front() << endl;
		cout << "vector.back()= " << c.back() << endl;
		cout << "vector.capacity()= " << c.capacity() << endl; //vectorʵ�ʵĴ�С

		//���ﻹ��һ�β�������ĳ����Թ���ûд
	}
}

#include <list>
namespace p5_list //list���ڴ治������˫������
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
		cout << "list.max_size()= " << c.max_size() << endl; //���ؿ����ɵ����Ԫ����
		//ʡ�Բ��ִ���

	}
}

#include<forward_list>

namespace p5_forward_list //�������� 
{
	//����������push_front()����
}

namespace p5_deque //˫�˶��У��ڴ��Ƿֶ�����buffer���������˿���
{

}

//p6 ����ʽ�������ҷǳ��� �������������ڲ���֮�����Զ����кõ�ô������

namespace p6_multiset //�����ظ������ݣ����ݱ���Ϊ�����
{
	//����������insert()����
}

namespace p6_multimap //�����ظ������ݣ����ݱ���Ϊ�����
{
	//insert(pair<keytype,valuetype>(key,value))
}

namespace p6_unordered_multiset //���ݱ���Ϊhash table
{
	//insert()
	//bucket_count() bucket_size()�����еķ���
}

namespace p6_set //�����ظ���������Ϊ��Ч
{

}

namespace p6_map //�������������ͬkey���ǲ�ͬvalue�����ݻ���ô��???
{
	//��ֵ��ʽ mapname[key]=value
}


//p7 allocator �����������ڷ����ڴ棬�Թ�




//P8��׼��Դ��λ�ã�gnu4.9.2\include\c++\bits\stl_xxx

//P9������������ʹ�÷�����ʱ����ͨ����������ʵ���㷨

//P11 ��VC6��GCC2.9�ı�׼���У�allocators��������ͨ������operator new()ȥʵ�ַ����ڴ棬��operator new()���յ��õ���malloc()������over head������
//GCC2.9��ʵ���õķ�������alloc��<stl_alloc.h>�У�
//GCC4.9��ʹ�ûص���VC6�ķ�������ԭ������GCC���Ѿ���22�汾��

//p13
