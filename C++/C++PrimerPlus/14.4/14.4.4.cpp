//用模板参数来定义数组的大小
#include<iostream>
#include<cstdlib>

using namespace std;

namespace array
{
	template<class T, int n>
	class ArrayTP
	{
	private:
		T ar[n];
	public:
		ArrayTP();
		explicit ArrayTP(const T& v); //数组中的元素都是v
		virtual T& operator[](int i);
		virtual T operator[](int i) const;
	};
	template<class T, int n>
	ArrayTP<T, n>::ArrayTP()
	{
		//这里构造函数有报错，私有成员ar没有初始化
	}

	template<class T, int n>
	ArrayTP<T, n>::ArrayTP(const T& v)
	{
		for (int i = 0; i < n; i++)
			ar[i] = v;
	}

	template<class T, int n>
	T& ArrayTP<T, n>::operator[](int i)
	{
		if (i < 0 || i >= n)
			exit(EXIT_FAILURE);
		return ar[i];
	}

	template<class T, int n>
	T ArrayTP<T, n>::operator[](int i)const
	{
		if (i < 0 || i >= n)
			exit(EXIT_FAILURE);
		return ar[i];
	}

	void test_array() //程序清单14.18
	{
		ArrayTP<ArrayTP<int, 5>, 10>twodee; //二维数组，10行5列
		ArrayTP<int, 10>sums; //每行的数字和
		ArrayTP<double, 10>aves; //每行的平均数
		
		int i, j;
		for (i = 0; i < 10; i++)
		{
			sums[i] = 0;
			for (j = 0; j < 5; j++)
			{
				twodee[i][j] = (i + 1) * (j + 1); //随机赋值
				sums[i] += twodee[i][j];
			}
			aves[i] = (double)sums[i] / 10;
		}

	}
}
