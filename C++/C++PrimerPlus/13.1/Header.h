#ifndef BASECLASS
#define BASECLASS
class BaseClass
{
private:
	int data1;
public:
	int data2;
	BaseClass(int a, int b);
	virtual void show() const; //�鷽����const����˼������������ܸı�ԭֵ
};

//���м̳У���is-a(is a kind of)��ϵ�����м̳в�����has-a��ϵ
class DerivedClass : public BaseClass
{
private:
	int data3;
public:
	DerivedClass(int c, BaseClass bc);
	virtual void show() const;
};
#endif