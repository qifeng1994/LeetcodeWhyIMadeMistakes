//��¼һЩ����cppreference.com��˵��
#include <iostream>
using namespace std;

namespace language
{
	#if 0
		std::cout << "��һ�䲻�ᱻִ�У��������ᱻ����\n";
	#endif

	void ascii_()
	{
		char i = 65; //A
		cout << "��ӡASCII���б��Ϊ" << int(i) << "���ַ�:" << i;
	}

	void sizeof_()
	{
		struct BaseData { int a; };
		BaseData bd;
		cout << "sizeof��������ڲ�ѯ��������͵Ĵ�С" << endl;
		cout << "ͨ�����Ͳ�ѯ: sizeof(BaseData) = " << sizeof(BaseData) << endl;
		cout << "ͨ�����ʽ��ѯ: sizeof bd = " << sizeof bd << endl;
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

		cout << "array a ��Ĭ��ֵ�ǣ�";
		for (const int& i : a)
			cout << i << ", ";
		cout << '\n';

		sort(a.begin(), a.end());
		cout << "����sort֮���array�ǣ�";
		for (const int& i : a)
			cout << i << ", ";
		cout << '\n';

		//Ԫ�ط���
		cout << "����at���ʵ�һ��Ԫ��a[0]=" << a.at(0) << ", ";
		a.at(0) = 6;
		cout << "����at�޸ĵ�һ��Ԫ�غ�a[0]=" << a.at(0) << endl;
		cout << "����front���ʵ�һ��Ԫ�� = " << a.front() << ", ����back�������һ��Ԫ�� = " << a.back() << endl;
		auto p = a.data();
		cout <<"data()���������ָ��p��Ĭ��ָ���һ��Ԫ�أ���ô�ڶ���Ԫ�ص�ֵ����* (p + 1)="<< * (p + 1) << endl;

		//������
		cout << "begin()����ָ����ʼ�ĵ���������ô*(a.begin())��ʾ��һ��Ԫ�ص�ֵ��" << *(a.begin()) << "������end()ָ�����һ��Ԫ�ص���һλ����˲��ܽ�����" << endl;

		//TODO:rbegin() rend()

		//����
		cout << "size()�������ɵ�Ԫ����" << a.size() << endl;
		cout << "max_size()���ؿ����ɵ����Ԫ����������array�������ǹ̶��ģ���˸���һ�����" << a.max_size() << endl;
		cout << "empty()��������Ƿ�Ϊ�գ�" << a.empty() << endl;

		//����
		array<int, 5> aa{ 5,7,8,9,10 };
		a.swap(aa);
		cout << "����swap()������array a��Ԫ���ǣ�";
		for (const int& i : a)
			cout << i << ", ";
		cout << '\n';
		//TODO:fill()
	}

	void test_vector()
	{
		//���캯��
		vector<string> v1{ "a1","b2","c3"}; //��ʼ��
		vector<string> v2(3, "d4"); //(3)���캯��
		for (auto& e : v2) { cout << e <<","; } cout << endl;

		//���� empty size
		cout << "size()�������ɵ�Ԫ����=" << v1.size() << ",max_size()���ؿ����ɵ����Ԫ����=" << v1.max_size() << endl;
		cout << "capacity()���ص�ǰ�洢�ռ������ɵ�Ԫ����=" << v1.capacity() << endl;
		//TODO:reserve shrink_to_fit

		//�޸���
		cout << "insert()�кܶ��÷���������õ�����ʵ�����Ĳ���" << endl;
		v1.push_back("e5");
		v1.pop_back();
		v1.erase(v1.begin());
	}
}

namespace algor
{
	//�޸����еĲ���
	//TODO:all_of,for_each,find_if
	void count_()
	{
		vector<int> v{ 1,2,2,2 };
		int num = count(v.begin(), v.end(), 2);
		cout << "vector v ���� " << num << " ������2" << endl;
	}

	void mismatch_()
	{
		vector<string> v1{ "a","b","c","d" };
		vector<string> v2{ "a","b","c","e" };
		auto pa = mismatch(v1.begin(), v1.end(), v2.begin());
		cout <<"mismatch()ָ���׶��������Ԫ�صĵ����� " << *pa.first << " " << *pa.second << endl;
		//�ٷ��������кܶྫ���д��
	}

	void find_end_()
	{
		vector<int> v1{ 1,2,3,4,1,2,3,4,5 };
		vector<int> v2{ 1,2,3 };
		vector<int>::iterator result;
		result = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
		cout << "find_end()������v1�����һ�γ���v2����ʼ�ĵ����� ָ��v1�еĵ� " <<distance(v1.begin(),result)+1<<" ��Ԫ�� " << *result << endl;
	}

	void find_first_of_()
	{
		vector<int> v1{ 0,1,2,3,4,5 };
		vector<int> v2{ 6,7,3,2 };
		auto result = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
		cout <<"find_first_of()������v1���״γ���v2�к��е�Ԫ�صĵ����� �״γ��ֵ�Ԫ���� " << *result << endl;
	}

	void adjacent_find_()
	{
		vector<int> v1{ 0,1,2,3,40,40,41,41,5 };
		auto i1 = adjacent_find(v1.begin(), v1.end()); //���ص�����
		cout << "adjacent_find()������Χ�����������ȵ�Ԫ��, v1���׸���ȵ�Ԫ���� ��" << distance(v1.begin(),i1)<<"����Ԫ���� " <<*i1<< endl;

		//TODO
		cout << "adjacent_find()�����Ի��������ж�" << endl;
	}

	void search_()
	{
		string str = "why waste time learning, when ignorance is instantaneous?";
		string substr = "learning";
		auto result = search(str.begin(), str.end(), substr.begin(), substr.end());
		cout << "search()������Χ���״γ���ĳ�������У�str���׸���ȵ��������� ��" << distance(str.begin(),result)<<"����Ԫ���� " << *result << endl;
	}
}

//int main()
//{
//	algor::search_();
//	return 0;
//}

//c11�����ԣ�lambda���ʽ