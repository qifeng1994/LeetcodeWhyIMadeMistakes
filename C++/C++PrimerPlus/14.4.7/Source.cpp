#include<iostream>
using namespace std;

namespace tempmem //程序清单14.20
{
	template<typename T>
	class beta
	{
	private:
		//模板中嵌套模板
		template<typename V>
		class hold
		{
		private:
			V val;
		public:
			hold(V v = 0) :val(v) {}
			void show()const { cout << val << endl; }
			V value()const { return val; }
		};

		hold<T> q;
		hold<int> n;
	public:
		beta(T t, int i) :q(t), n(i) {}
		template<typename U>
		U blab(U u, T t) { return (n.value() + q.value()) * u / t; }
		void SHOW()const { q.show(); n.show(); }
	};

	void test_tempmem()
	{
		beta<double> guy(3.5, 3);
		cout << "T 是 double" << endl;
		guy.SHOW();

		cout << "U 是 int" << endl;
		cout << guy.blab(10, 2.3) << endl;
	}
}

namespace tempparm
{
	//一个stack的类
	template <class Type>
	class Stack
	{
	private:
		enum { MAX = 10 };   
		Type items[MAX];    
		int top;            
	public:
		Stack();
		bool isempty();
		bool isfull();
		bool push(const Type& item); 
		bool pop(Type& item);        
	};

	template <class Type>
	Stack<Type>::Stack()
	{
		top = 0;
	}

	template <class Type>
	bool Stack<Type>::isempty()
	{
		return top == 0;
	}

	template <class Type>
	bool Stack<Type>::isfull()
	{
		return top == MAX;
	}

	template <class Type>
	bool Stack<Type>::push(const Type& item)
	{
		if (top < MAX)
		{
			items[top++] = item;
			return true;
		}
		else
			return false;
	}

	template <class Type>
	bool Stack<Type>::pop(Type& item)
	{
		if (top > 0)
		{
			item = items[--top];
			return true;
		}
		else
			return false;
	}

	//程序清单14.21
	template<template<typename T>class Thing>
	class crab
	{
	private:
		Thing<int> s1;
		Thing<double> s2;
	public:
		crab() {};
		bool push(int a, double x) { return s1.push(a) && s2.push(x); }
		bool pop(int& a, double& x) { return s1.pop(a) && s2.pop(x); }
	};

	void test_crab()
	{
		crab<Stack> nubula;
		nubula.push(4, 3.5);
		nubula.push(5, 4.5);
		int a;
		double b;
		while (nubula.pop( a, b))
			cout << a << ", " << b << endl;

	}
}
int main()
{
	// tempmem::test_tempmem();
	tempparm::test_crab();
	return 0;
}