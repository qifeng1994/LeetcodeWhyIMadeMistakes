#ifndef CLASSS
#define CLASSS
class classs
{
private:
	char data1;
public:
	classs(); //Ĭ�ϵĹ��캯��
	classs(char c, int i); //�Զ��幹�캯��
	~classs(); //��������,ִ�н������Զ�����
	void add(int a, int b);
	void show() const;
	int data2;
	void compare(classs& );
};
#endif

