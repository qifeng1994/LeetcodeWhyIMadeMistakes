//多重公有继承，表示的是is-a的关系
#include <string>
#include <iostream>
#include <array>
using namespace std;

class Worker //抽象基类
{
private:
	string fullname;
	long id;
public:
	Worker() :fullname("no one"), id(0) {}
	Worker(const string& s, long n) :fullname(s), id(n) {}
	virtual ~Worker() = 0; //纯虚析构函数，有什么意义呢
	virtual void Set(); //set 私有成员
	virtual void Show()const; //get 私有成员
};
Worker::~Worker() {} //这么写表示实现了虚函数
void Worker::Set()
{
	cout << "enter worker's name: ";
	getline(cin, fullname);
	cout << "enter worker's id: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
void Worker::Show()const
{
	cout << "name: " << fullname << endl;
	cout << "employee id: " << id << endl;
}





class Waiter :public Worker
{
private:
	int panache; //貌似是一种饮料的名字
public:
	Waiter() :Worker(), panache(0) {}
	Waiter(const string& s, long n, int p = 0) :Worker(s, n), panache(p) {}
	Waiter(const Worker& wk, int p = 0) :Worker(wk), panache(p) {}
	void Set();
	void Show()const;
};
void Waiter::Set()
{
	Worker::Set();
	cout << "enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}
void Waiter::Show()const
{
	cout << "category: waiter\n";
	Worker::Show();
	cout << "panache rating: " << panache << endl;
}



class Singer :public Worker
{
protected:
	enum {other,alto,contralto,soparano,bass,baritone,tenor}; //唱法
	enum{vtype=7};
private:
	array<string,vtype> pv { "other", "alto", "contralto","soprano", "bass", "baritone", "tenor" }; //源程序是一个指针，报错，这里修改为了容器
	int voice;
public:
	Singer() :Worker(), voice(other) {} //枚举的用法????
	Singer(const string& s, long n, int v = other) :Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other) :Worker(wk), voice(v) {}
	void Set();
	void Show()const;
};

void Singer::Set()
{
	Worker::Set();
	cout << "enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < vtype; i++)
	{
		cout << i << ": " << pv[i] << "   ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= vtype))
		cout << "Please enter a value >= 0 and < " << vtype << endl;
	while (cin.get() != '\n')
		continue;
}
void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}


const int LIM = 4;
int main()
{
	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;

	Worker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->Set();
	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
	// std::cin.get();
	return 0;
}