#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>
#include<cctype> //tolower()��дתСд
using namespace std;


char toLower(char ch) { return tolower(ch); }

string& ToLower(string& st)
{
	transform(st.begin(), st.end(), st.begin(), toLower); //Ӧ��toLower��������begin��end���ѽ���洢��ʼ��begin��������
	return st;
}

void display(const string& s)
{
	cout << s << " ";
}

void test_algo() //�����嵥16.19 ����һ�ѵ��ʣ�ȫ��ת����Сд����ͳ��ÿ�����ʳ��ֵĴ���
{
	vector<string> words;
	cout << "enter words (enter quit to quit)\n";
	string input;
	while (cin >> input && input!="quit")
		words.push_back(input);
	cout << "you enter the following words:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	//�������������������ֱ��дwordset.begin()ô������
	set<string> wordset;
	transform(words.begin(), words.end(),
		insert_iterator<set<string>>(wordset, wordset.begin()),
		ToLower);
	// transform(words.begin(), words.end(),wordset.begin(),ToLower); //��ôд�ᱨ��

	cout << "new list of words:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	////����transform֮��ԭֵҲ����д��
	//cout << "test vector words is changed or not" << endl;
	//for_each(words.begin(), words.end(), display);
	//cout << endl;

	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si); //����[]��ʲô�÷�������

	cout << "word frequency:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ":" << wordmap[*si] << endl;
}

int main()
{
	test_algo();
	return 0;
}
