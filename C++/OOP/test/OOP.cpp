//侯捷老师关于C++面向对象高级编程的笔记
#include <iostream>
using namespace std;

//P6复习complex类的实现过程，这是一个复数类，包含实数和虚数
namespace p6
{
	class complex
	{
	public:
		complex(double r = 0, double i = 0)
			:re(r), im(i) {} //构造函数初始化列表，默认初始值是(0,0)
		complex& operator += (const complex&); //运算符重载
		double real() const { return re; } //const写在函数名后面表示这个函数不会改变数据
		double imag() const { return im; }
	private:
		double re, im;

		friend complex& __doapl(complex*, const complex&);
	};

	inline complex&
		complex::operator+=(const complex& r)
	{
		return __doapl(this, r); //this是类的引用
	}

	inline complex&
		__doapl(complex* ths, const complex& r) //复数的加法
	{
		ths->re += r.re;
		ths->im += r.im;
		return *ths;
	}

	inline complex
		operator + (const complex& x, const complex& y)
	{
		return complex(x.real() + y.real(),
			x.imag() + y.imag());
	}

	inline complex
		operator + (const complex& x, double y)
	{
		return complex(x.real() + y, x.imag());
	}

	inline complex
		operator + (double x, const complex& y)
	{
		return complex(x + y.real(), y.imag());
	}

	std::ostream&
		operator << (std::ostream& os, const complex& x) //运算符重载,为了满足cout<<c1<<c2这种用法，返回值设置为ostream&
	{
		return os << '(' << x.real() << ',' << x.imag() << ')';
	}

	void text_complex()
	{
		complex c1(1, 2);
		complex c2(3, 4);
		std::cout << c1 + c2;
	}
}

//p8堆 栈 内存管理
//调用构造函数后，对象存储在stack中
//利用new来动态创建的对象则存储在heap中

//P9string类实现的复习
#include <string>
//std::size_t strlen( const char* str ); 参数str是指向字符串的指针，函数返回字符串str的长度
namespace p9
{
	class String
	{
	private:
		char* m_data; //利用指针实现动态分配内存
	public:
		String(const char* cstr = 0); //默认的构造函数,cstr是指向字符串的指针
		String(const String& str); //拷贝构造 String s1("hello"); String s2(s1);
		String& operator=(const String& str); //拷贝赋值 String s3=s1;
		~String(); //析构函数

		char* get_c_str() const { return m_data; }
	};

	inline
		String::String(const char* cstr)
	{
		if (cstr)
		{
			//正常情况，例如 String s2("hello");
			m_data = new char[1 + strlen(cstr)];
			strcpy(m_data, cstr);
		}
		else
		{
			//如果是空字符串,例如 String s1();
			m_data = new char[1];
			*m_data = '\0';
		}
	}

	inline
		String::~String()
	{
		delete[] m_data;
	}

	inline
		String::String(const String& str)
	{
		m_data = new char[1 + strlen(str.m_data)];
		strcpy(m_data, str.m_data);
	}

	inline
		String& String::operator=(const String& str)
	{
		if (this == &str) return *this;

		delete[]m_data;
		m_data = new char[1 + strlen(str.m_data)];
		strcpy(m_data, str.m_data);
		return *this;
	}

	ostream& operator << (ostream& os, const String& str)
	{
		os << str.get_c_str();
		return os;
	}

	void test_string()
	{
		String s1("hello"); //拷贝构造
		String s2(s1); //拷贝构造
		String s3 = s1; //拷贝赋值
		cout << s1 << endl << s2 << endl << s3 << endl;
	}
}

//p10 static
namespace p10
{
	class Account
	{
	public:
		static double m_rate;
		static void set_rate(const double& x) { m_rate = x; }
	};

	double Account::m_rate = 8.0; //静态数据必须定义，也可以不赋值具体的数字

	void test_static()
	{
		Account::set_rate(5.0); 
		cout << "通过class name调用static函数 m_rate = " << Account::m_rate << endl;
		Account a;
		a.set_rate(7.0); 
		cout << "通过object调用static函数 m_rate = " << Account::m_rate << endl;
	}
}

//P11类与类的三个关系：
//composition表示has-a关系
//设计模式 adapter 适配器模式

//composition by reference表示两个类通过指针相连。指针指向类的实现。也叫做委托

//inheritance表示is-a-kind-of关系

//P12 虚函数
//设计模式：template method 用子类调用父类的方法
namespace p12_1
{
	class CDocument //application framework
	{
	public:
		void OnFileOpen();
		virtual void Serialize() { cout << "调用父类虚函数serialize()" << endl; } //这个地方按理说应该是空的虚函数，认为cdocument是一个抽象类
	};

	void CDocument::OnFileOpen()
	{
		cout << "调用父类函数onfileopen()" << endl;
		Serialize();
	}

	class CMyDoc :public CDocument //application
	{
	public:
		virtual void Serialize() { cout << "调用子类虚函数serialize()" << endl; }
	};

	void test_vir()
	{
		CMyDoc myDoc;
		myDoc.OnFileOpen(); //最终调用的是子类虚函数
	}
}

//设计模式 observer or Publish/subscribe 观察者模式:委托+继承
namespace p12_2
{

}

#include <vector>
//P13
//设计模式 composite：委托+继承
namespace p13_1
{
	class Component
	{
	private:
		int value;
	public:
		Component(int val) { value = val; }
		virtual void add(Component*) {} //空的虚函数
	};

	class Primitive:public Component
	{
	public:
		Primitive(int val) :Component(val) {}
	};

	class Composite :public Component
	{
	private:
		vector<Component*> c; //composite类可以放component对象
	public:
		Composite(int val) :Component(val) {}
		void add(Component* elem) { c.push_back(elem); } //实现了委托
	};
}

//设计模式 prototype:委托+继承
namespace p13_2
{

}
//p15 conversion function 分数转换函数的例子
namespace p15
{
	class Fraction
	{
	private:
		int m_numerator; //分子
		int m_denominator; //分母
	public:
		Fraction(int num, int den=1)
			:m_numerator(num), m_denominator(den){}

		//这个函数表示这个类可以转换为double类型
		operator double() const
		{
			return (double)m_numerator / m_denominator;
		}
	};

	void test_fraction()
	{
		Fraction f(3,5);
		double data = f + 4; //调用operator double()将f转为double, data=4.6
		cout << data << endl;
	}
}

//p16 explicit 用于修饰构造函数，表示构造函数只能去用作初始化
namespace p16
{
	class Fraction
	{
	private:
		int m_numerator; //分子
		int m_denominator; //分母
	public:
		explicit Fraction(int num, int den = 1)
			:m_numerator(num), m_denominator(den) {}

		operator double() const
		{
			cout << "将Fraction类型转换为double" << endl;
			return (double)m_numerator / m_denominator;
		}

		Fraction operator+(const Fraction& f) //Fraction this + Fraction f
		{
			cout << "两个Fraction类型相加" << endl;
			return Fraction((this->m_numerator * f.m_denominator + this->m_denominator * f.m_numerator), this->m_denominator * f.m_denominator);
		}
	};

	void test_fraction()
	{
		Fraction f1(3, 5);
		Fraction f2(2, 5);
		double data = f1 + f2; 
		cout <<"f1 + f2 = " << data << endl;
	}
}

//p17 pointer-like classes 功能跟指针很像的类
namespace p17
{
	//一种广义的智能指针
	template<class T>
	class shared_ptr
	{
	private:
		T* px; //px是指向T类型对象的指针
	public:
		T& operator*()const { cout << "3.调用类模板的解引用操作符 " << endl; return*px; }
		T* operator->()const { cout << "6.调用类模板的箭头操作符 " << endl; return px; }
		shared_ptr(T* p) :px(p) { cout << "1.调用类模板的构造函数" << endl; }
	};

	struct test_struct
	{
		void test_method() { cout << "7.调用结构体的成员函数" << endl; }
	};

	void test_ptr()
	{
		shared_ptr<test_struct> sp(new test_struct); 
		cout << "2.sp虽然shared_ptr类型的对象，但是他的功能可以视为是指向test_struct类型的指针" << endl;
		test_struct ts(*sp);
		cout << "4.ts是test_struct类型的对象" << endl;
		cout << "5.接下来，利用智能指针去调用test_struct类型中的函数" << endl;
		sp->test_method();
		//如果用普通指针去声明的话，同样可以去调用结构体的方法，区别在于智能指针可以由开发者去定义想要的操作

		cout << "如果用普通指针去实现的话：" << endl;
		test_struct* ptr = new test_struct;
		ptr->test_method();
	}

	//迭代器也可以理解为是功能跟指针很像的类
}

//p18 function-like classes 功能跟函数很像的类，比如std中的仿函数
namespace p18
{

}

//p21 函数模板
namespace p21
{
	template<class T>
	const T& min(const T& a, const T& b)
	{
		return a < b ? a : b; //返回较小的对象
	}

	class stone
	{
	private:
		int _w, _h, _weight;
	public:
		stone(int w=0, int h=0, int we=0)
			:_w(w), _h(h), _weight(we) {}
		bool operator< (const stone& s) const { return this->_weight < s._weight; } //运算符重载
		int get_stone_weight() const { return _weight; }
	};

	void test_function_template()
	{
		stone s1(1, 1, 2), s2(2, 2, 1), s3;
		s3 = min(s1, s2);
		cout << "利用函数模板比较stone类的对象中更小的一个重量是 " << s3.get_stone_weight() << endl;
	}
}

//p22 member template 成员模板
namespace p22
{
	template<class T1, class T2>
	struct pair
	{
		T1 first;
		T2 second;
		pair():first(T1()),second(T2()){}
		pair(const T1& a, const T2& b):first(a),second(b){}

		//这里暗指U1:T1 U2:T2
		template<class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

	};
}

//p23 specialization 模板特化
namespace p23
{
	template<class Key>
	struct hash {};

	template<>
	struct hash<int> { int a; };
	template<>
	struct hash<char> { char c; };
}

//p24 partial specialization 模板偏特化
namespace p24
{
	template<class T1, class T2>
	class cl {};

	template<class T2>
	class cl<bool, T2> {};

	template<class T>
	class cla {};

	template<class U>
	class cla<U*> {}; //范围偏特化，默认模板T是任意类型，U是特指指针类型
}

//p25 template template parameter 模板模板参数 （跳过）

//p27 variadic templates 数量不定的模板参数，例子
namespace p27
{
	//template<typename T, typename...Types>
	//void print(const T& firstArg, const Types&...args)
	//{
	//	std::cout << firstArg << std::endl;
	//	print(args...);
	//}

	//void print() {}

	//void test_print()
	//{
	//	print(1, "hello", 2, "world"); //这里实现了递归打印
	//}

	void tprintf(const char* format) // 基础函数
	{
		std::cout << format;
	}

	template<typename T, typename... Targs>
	void tprintf(const char* format, T value, Targs... Fargs) // 递归变参函数
	{
		for (; *format != '\0'; format++)
		{
			if (*format == '%')
			{
				std::cout << value;
				tprintf(format + 1, Fargs...); // 递归调用
				return;
			}
			std::cout << *format;
		}
	}
}

//p28 reference的小结
namespace p28
{
	void func1(int i) { cout << "pass by value " << i <<endl; }
	void func2(int& i) { cout << "pass by reference " << i << endl; }
	void test_reference()
	{
		int x = 0;
		int* p = &x; //p is a pointer to x
		int& r = x; //r is a reference to x
		int y = 5;
		r = y; //r x 都是5

		func1(x);
		func2(x);
	}
}

#include <list>
//p30 virtual pointer 和 virtual table 虚函数的使用方法之一，多态
namespace p30
{
	//合适的例子待补充
	class cl
	{
	public:
		virtual void func1() { cout << "调用基类的函数"; }
	};

	class subcl:public cl
	{
	public:
		virtual void func1() { cout << "调用父类的函数"; }
	};

	class subsubcl :public subcl
	{
	public:
		void func1() { cout << "调用子类的函数"; }
	};

	list<cl*> mylist;
	//TODO 如何实现多态
}

//p36

int main()
{
	
	return 0;
}

