#ifndef CLASSS
#define CLASSS
class classs
{
private:
	char data1;
public:
	classs(); //默认的构造函数
	classs(char c, int i); //自定义构造函数
	~classs(); //析构函数,执行结束后自动调用
	void add(int a, int b);
	void show() const;
	int data2;
	void compare(classs& );
};
#endif

