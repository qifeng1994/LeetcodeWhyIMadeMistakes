//类模板的实际应用就是容器，函数模板的实际应用是stl中的各种算法

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//在类中使用动态数组和构造函数参数来提供元素数目
using namespace std;
namespace stack_pointer
{
	template<class Type>
	class Stack
	{
	private:
		enum{SIZE=10};
		int stacksize;
		Type* items;
		int top; //top其实用于表明当前栈中实际有几个元素
	public:
		explicit Stack(int ss = SIZE);
		Stack(const Stack& st);
		~Stack() { delete[]items; } //
		bool isempty() { return top == 0; }
		bool isfull() { return top == stacksize; }
		bool push(const Type& item);
		bool pop(Type& item);
		Stack& operator=(const Stack& st); //目的是为了构造函数？？
	};

	template<class Type>
	Stack<Type>::Stack(int ss) :stacksize(ss), top(0) { items = new Type[stacksize]; } //栈的大小是动态的，同时初始化了一个指针

	template<class Type>
	Stack<Type>::Stack(const Stack& st)
	{
		stacksize = st.stacksize;
		top = st.top;
		items = new Type[stacksize];
		for (int i = 0; i < top; i++)
			items[i] = st.items[i];
	}

	template<class Type>
	bool Stack<Type>::push(const Type& item)
	{
		if (top < stacksize)
		{
			items[top++] = item;
			return true;
		}
		else
			return false;
	}

	template<class Type>
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

	template<class Type>
	Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st)
	{
		if (this == &st)
			return *this; //this是对自身的引用，这种写法之前在侯捷老师的程序中见过

		delete[]items;
		stacksize = st.stacksize;
		top = st.top;
		items = new Type[stacksize];
		for (int i = 0; i < top; i++)
			items[i] = st.items[i];
		return *this;
	}

	void test_stack() //st栈中存放的都是指针，整个过程其实是把in数组中存放的指针，以st栈为中转搬运到out数组中
	{
		//程序清单14.16
	}
}


