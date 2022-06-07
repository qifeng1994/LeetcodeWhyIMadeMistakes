#pragma once
#ifndef STACK_H
#define STACK_H
//这里相当于是自定义一个叫Stack的类，所以没有引用<stack>
template<class Type>
class Stack
{
private:
	Type items[10];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(Type& item); //这里应该是只push一个元素
	bool pop(Type& item);
};

template<class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template<class Type>
bool Stack<Type>::isempty()
{
	return top == 0;
}

template<class Type>
bool Stack<Type>::isfull()
{
	return top == 10;
}

template<class Type>
bool Stack<Type>::push(Type& item)
{
	if (top < 10)
	{
		top++;
		items[top] = item;
		return true;
	}
	else
	{
		return false;
	}
}

template<class Type>
bool Stack<Type>::pop(Type& item) //把出栈的元素赋值给参数
{
	if (top > 0)
	{
		item = items[top];
		top--;
		return true;
	}
	else
	{
		return false;
	}
}
#endif // !STACK_H
