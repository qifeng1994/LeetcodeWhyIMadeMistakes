#ifndef BASECLASS
#define BASECLASS
class BaseClass
{
private:
	int data1;
public:
	int data2;
	BaseClass(int a, int b);
	virtual void show() const; //虚方法，const的意思是这个函数不能改变原值
};

//公有继承，是is-a(is a kind of)关系，公有继承不建立has-a关系
class DerivedClass : public BaseClass
{
private:
	int data3;
public:
	DerivedClass(int c, BaseClass bc);
	virtual void show() const;
};
#endif