#pragma once
#ifndef STACK_H
#define STACK_H
//�����൱�����Զ���һ����Stack���࣬����û������<stack>
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
	bool push(Type& item); //����Ӧ����ֻpushһ��Ԫ��
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
bool Stack<Type>::pop(Type& item) //�ѳ�ջ��Ԫ�ظ�ֵ������
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
