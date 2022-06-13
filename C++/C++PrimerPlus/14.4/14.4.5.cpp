#include<iostream>
#include<string>
using namespace std;

namespace par
{
	template<class T1, class T2>
	class pair
	{
	private:
		T1 a;
		T2 b;
	public:
		T1 first()const { return a; }
		T2 second()const { return b; }
		T1& first() { return a; } //这里为什么不写const
		T2& second() { return b; }
		pair(const T1& aval, const T2& bval) :a(aval), b(bval) {}
		pair() {}
	};

	void test_pair()
	{
		pair<string, int> DataTable[2]
		{
			pair<string, int>{"aa",2},
			pair<string, int>("bbb",3)
		};

		cout << DataTable[0].first() << endl;
		cout << DataTable[1].first() << endl;
	}
}

int main()
{
	par::test_pair();
	return 0;
}