#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>
#include<cctype> //tolower()大写转小写
using namespace std;


char toLower(char ch) { return tolower(ch); }

string& ToLower(string& st)
{
	transform(st.begin(), st.end(), st.begin(), toLower); //应用toLower函数到从begin到end，把结果存储在始于begin的数据中
	return st;
}

void display(const string& s)
{
	cout << s << " ";
}

void test_algo() //程序清单16.19 输入一堆单词，全部转换成小写，再统计每个单词出现的次数
{
	vector<string> words;
	cout << "enter words (enter quit to quit)\n";
	string input;
	while (cin >> input && input!="quit")
		words.push_back(input);
	cout << "you enter the following words:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	//下面迭代器的声明可以直接写wordset.begin()么？？？
	set<string> wordset;
	transform(words.begin(), words.end(),
		insert_iterator<set<string>>(wordset, wordset.begin()),
		ToLower);
	// transform(words.begin(), words.end(),wordset.begin(),ToLower); //这么写会报错

	cout << "new list of words:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	////经过transform之后原值也被改写了
	//cout << "test vector words is changed or not" << endl;
	//for_each(words.begin(), words.end(), display);
	//cout << endl;

	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si); //这里[]是什么用法？？？

	cout << "word frequency:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ":" << wordmap[*si] << endl;
}

int main()
{
	test_algo();
	return 0;
}
