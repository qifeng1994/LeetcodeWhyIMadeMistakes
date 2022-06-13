//��ģ���ʵ��Ӧ�þ�������������ģ���ʵ��Ӧ����stl�еĸ����㷨

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//������ʹ�ö�̬����͹��캯���������ṩԪ����Ŀ
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
		int top; //top��ʵ���ڱ�����ǰջ��ʵ���м���Ԫ��
	public:
		explicit Stack(int ss = SIZE);
		Stack(const Stack& st);
		~Stack() { delete[]items; } //
		bool isempty() { return top == 0; }
		bool isfull() { return top == stacksize; }
		bool push(const Type& item);
		bool pop(Type& item);
		Stack& operator=(const Stack& st); //Ŀ����Ϊ�˹��캯������
	};

	template<class Type>
	Stack<Type>::Stack(int ss) :stacksize(ss), top(0) { items = new Type[stacksize]; } //ջ�Ĵ�С�Ƕ�̬�ģ�ͬʱ��ʼ����һ��ָ��

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
			return *this; //this�Ƕ���������ã�����д��֮ǰ�ں����ʦ�ĳ����м���

		delete[]items;
		stacksize = st.stacksize;
		top = st.top;
		items = new Type[stacksize];
		for (int i = 0; i < top; i++)
			items[i] = st.items[i];
		return *this;
	}

	void test_stack() //stջ�д�ŵĶ���ָ�룬����������ʵ�ǰ�in�����д�ŵ�ָ�룬��stջΪ��ת���˵�out������
	{
		//�����嵥14.16
	}
}


