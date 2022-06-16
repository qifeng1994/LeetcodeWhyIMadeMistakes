#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

void test_iterator() //�����嵥16.10
{
	//��copy���������飬������������ʾ���Ƶ���ʼλ��
	int casts[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>dice(10); //�������û��ָ����С������ִ�е�ʱ��ᱨ��
	copy(casts, casts + 10, dice.begin());

	//����������������ʾ��int���Ϊchar����
	ostream_iterator<int, char>out_iter(cout, ",");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;

	//�������
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;

	//rbegin() rend()����һ��������������������е����������������ݼ�
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ",";
	cout << endl;
}

#include <string>
#include <algorithm>
//�����嵥16.11
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
	//Ϊ��Ϊwords��vector<string>�����������������
	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;
	//�����������������ָ��Ҫ��ͷ������
	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
	for_each(words.begin(), words.end(), output);
	cout << endl;

}

#include <list>
//�����嵥16.12
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

	three.remove(2); //�Ƴ���2��Ԫ��
	three.splice(three.begin(), one); //������x�����ݲ��뵽three.begin()ǰ��
	three.unique(); //��������ͬ��Ԫ��ѹ��Ϊ����Ԫ��
	three.sort(); //����<���������
	three.unique();
	two.sort();
	three.merge(two); //������two��three�ϲ���ǰ��������������Ѿ����򣬺ϲ���ľ����������������three��

	for_each(three.begin(), three.end(), outint);
}

#include <set>
//�����嵥16.13
void test_set()
{
	const int N = 6;
	string s1[N]{ "buffoon","thinkers","for","heavy","can","for" };
	string s2[N] = { "metal","any","food","elegant","deliver","for" };
	//�����������Զ�����
	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);

	for_each(A.begin(), A.end(), output); //set�����в�������ͬ�ļ�ֵ
	cout << endl;
	ostream_iterator<string, char> out(cout, ","); //����һ�����������
	set_union(A.begin(), A.end(), B.begin(), B.end(), out); //����
	cout << endl;
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out); //����
	cout << endl;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out); //���ϵĲ��һ�����ϼ�ȥ����
	cout << endl;

	set<string> C;
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C,C.begin())); //ȡ���������
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3{ "grungy" };
	C.insert(s3);
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out); //�������������Ԫ��
	cout << endl;
}

#include <map>
//�����嵥16.14
void test_multimap() //һ���������ж��ֵ
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

	cout << "num of cities with area code 415: " << codes.count(415) << endl; //���ؼ�415��Ӧ��ֵ�ĸ���
	MapCode::iterator it; //ΪʲôҪ������ȡ����������
	for (it = codes.begin(); it != codes.end(); ++it)
		cout << " " << (*it).first << " " << (*it).second << endl; //�����µ�for rangeд����ʵ���𣿣�
	
	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718); //equal_range���������������������Ƿ�װ��pair������ ����дautoӦ�ÿ���
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