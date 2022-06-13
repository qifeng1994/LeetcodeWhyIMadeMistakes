//��ģ���������������Ĵ�С
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
		explicit ArrayTP(const T& v); //�����е�Ԫ�ض���v
		virtual T& operator[](int i);
		virtual T operator[](int i) const;
	};
	template<class T, int n>
	ArrayTP<T, n>::ArrayTP()
	{
		//���ﹹ�캯���б���˽�г�Աarû�г�ʼ��
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

	void test_array() //�����嵥14.18
	{
		ArrayTP<ArrayTP<int, 5>, 10>twodee; //��ά���飬10��5��
		ArrayTP<int, 10>sums; //ÿ�е����ֺ�
		ArrayTP<double, 10>aves; //ÿ�е�ƽ����
		
		int i, j;
		for (i = 0; i < 10; i++)
		{
			sums[i] = 0;
			for (j = 0; j < 5; j++)
			{
				twodee[i][j] = (i + 1) * (j + 1); //�����ֵ
				sums[i] += twodee[i][j];
			}
			aves[i] = (double)sums[i] / 10;
		}

	}
}
