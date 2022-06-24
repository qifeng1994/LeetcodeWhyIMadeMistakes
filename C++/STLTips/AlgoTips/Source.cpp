#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void sort_test()
{
	//sort()Ĭ��������
	vector<int> numbers{ 99, 77, 33, 66, 22, 11, 44, 88 };
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>{cout, " "}); cout << endl;
	sort(numbers.begin(), numbers.end(), greater<>()); //�Զ��彵�����
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>{cout, " "}); cout << endl;

	vector<string> words{ "one", "two", "nine", "nine", "one", "three", "four", "five", "six" };
	sort(words.begin(), words.end());
	copy(words.begin(), words.end(), ostream_iterator<string>{cout, " "}); cout << endl;
	sort(words.begin(), words.end(), [](const string& s1, const string& s2) {return s1.back() > s2.back(); }); //lambda���ʽ�������str.back()�����ַ��������һ���ַ�
	copy(words.begin(), words.end(), ostream_iterator<string>{cout, " "}); cout << endl;

	//stable_sort()

	//partial_sort() ��������
	partial_sort(numbers.begin(), numbers.begin() + 5, numbers.end()); //ǰ5��Ԫ������
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>{cout, " "}); cout << endl;
}

int main()
{
	sort_test();

	return 0;
}