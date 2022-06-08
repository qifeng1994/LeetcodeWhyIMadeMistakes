//�����ʦ����C++�������߼���̵ıʼ�
#include <iostream>
using namespace std;

//P6��ϰcomplex���ʵ�ֹ��̣�����һ�������࣬����ʵ��������
namespace p6
{
	class complex
	{
	public:
		complex(double r = 0, double i = 0)
			:re(r), im(i) {} //���캯����ʼ���б�Ĭ�ϳ�ʼֵ��(0,0)
		complex& operator += (const complex&); //���������
		double real() const { return re; } //constд�ں����������ʾ�����������ı�����
		double imag() const { return im; }
	private:
		double re, im;

		friend complex& __doapl(complex*, const complex&);
	};

	inline complex&
		complex::operator+=(const complex& r)
	{
		return __doapl(this, r); //this���������
	}

	inline complex&
		__doapl(complex* ths, const complex& r) //�����ļӷ�
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
		operator << (std::ostream& os, const complex& x) //���������,Ϊ������cout<<c1<<c2�����÷�������ֵ����Ϊostream&
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

//p8�� ջ �ڴ����
//���ù��캯���󣬶���洢��stack��
//����new����̬�����Ķ�����洢��heap��

//P9string��ʵ�ֵĸ�ϰ
#include <string>
//std::size_t strlen( const char* str ); ����str��ָ���ַ�����ָ�룬���������ַ���str�ĳ���
namespace p9
{
	class String
	{
	private:
		char* m_data; //����ָ��ʵ�ֶ�̬�����ڴ�
	public:
		String(const char* cstr = 0); //Ĭ�ϵĹ��캯��,cstr��ָ���ַ�����ָ��
		String(const String& str); //�������� String s1("hello"); String s2(s1);
		String& operator=(const String& str); //������ֵ String s3=s1;
		~String(); //��������

		char* get_c_str() const { return m_data; }
	};

	inline
		String::String(const char* cstr)
	{
		if (cstr)
		{
			//������������� String s2("hello");
			m_data = new char[1 + strlen(cstr)];
			strcpy(m_data, cstr);
		}
		else
		{
			//����ǿ��ַ���,���� String s1();
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
		String s1("hello"); //��������
		String s2(s1); //��������
		String s3 = s1; //������ֵ
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

	double Account::m_rate = 8.0; //��̬���ݱ��붨�壬Ҳ���Բ���ֵ���������

	void test_static()
	{
		Account::set_rate(5.0); 
		cout << "ͨ��class name����static���� m_rate = " << Account::m_rate << endl;
		Account a;
		a.set_rate(7.0); 
		cout << "ͨ��object����static���� m_rate = " << Account::m_rate << endl;
	}
}

//P11�������������ϵ��
//composition��ʾhas-a��ϵ
//���ģʽ adapter ������ģʽ

//composition by reference��ʾ������ͨ��ָ��������ָ��ָ�����ʵ�֡�Ҳ����ί��

//inheritance��ʾis-a-kind-of��ϵ

//P12 �麯��
//���ģʽ��template method ��������ø���ķ���
namespace p12_1
{
	class CDocument //application framework
	{
	public:
		void OnFileOpen();
		virtual void Serialize() { cout << "���ø����麯��serialize()" << endl; } //����ط�����˵Ӧ���ǿյ��麯������Ϊcdocument��һ��������
	};

	void CDocument::OnFileOpen()
	{
		cout << "���ø��ຯ��onfileopen()" << endl;
		Serialize();
	}

	class CMyDoc :public CDocument //application
	{
	public:
		virtual void Serialize() { cout << "���������麯��serialize()" << endl; }
	};

	void test_vir()
	{
		CMyDoc myDoc;
		myDoc.OnFileOpen(); //���յ��õ��������麯��
	}
}

//���ģʽ observer or Publish/subscribe �۲���ģʽ:ί��+�̳�
namespace p12_2
{

}

#include <vector>
//P13
//���ģʽ composite��ί��+�̳�
namespace p13_1
{
	class Component
	{
	private:
		int value;
	public:
		Component(int val) { value = val; }
		virtual void add(Component*) {} //�յ��麯��
	};

	class Primitive:public Component
	{
	public:
		Primitive(int val) :Component(val) {}
	};

	class Composite :public Component
	{
	private:
		vector<Component*> c; //composite����Է�component����
	public:
		Composite(int val) :Component(val) {}
		void add(Component* elem) { c.push_back(elem); } //ʵ����ί��
	};
}

//���ģʽ prototype:ί��+�̳�
namespace p13_2
{

}
//p15 conversion function ����ת������������
namespace p15
{
	class Fraction
	{
	private:
		int m_numerator; //����
		int m_denominator; //��ĸ
	public:
		Fraction(int num, int den=1)
			:m_numerator(num), m_denominator(den){}

		//���������ʾ��������ת��Ϊdouble����
		operator double() const
		{
			return (double)m_numerator / m_denominator;
		}
	};

	void test_fraction()
	{
		Fraction f(3,5);
		double data = f + 4; //����operator double()��fתΪdouble, data=4.6
		cout << data << endl;
	}
}

//p16 explicit �������ι��캯������ʾ���캯��ֻ��ȥ������ʼ��
namespace p16
{
	class Fraction
	{
	private:
		int m_numerator; //����
		int m_denominator; //��ĸ
	public:
		explicit Fraction(int num, int den = 1)
			:m_numerator(num), m_denominator(den) {}

		operator double() const
		{
			cout << "��Fraction����ת��Ϊdouble" << endl;
			return (double)m_numerator / m_denominator;
		}

		Fraction operator+(const Fraction& f) //Fraction this + Fraction f
		{
			cout << "����Fraction�������" << endl;
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

//p17 pointer-like classes ���ܸ�ָ��������
namespace p17
{
	//һ�ֹ��������ָ��
	template<class T>
	class shared_ptr
	{
	private:
		T* px; //px��ָ��T���Ͷ����ָ��
	public:
		T& operator*()const { cout << "3.������ģ��Ľ����ò����� " << endl; return*px; }
		T* operator->()const { cout << "6.������ģ��ļ�ͷ������ " << endl; return px; }
		shared_ptr(T* p) :px(p) { cout << "1.������ģ��Ĺ��캯��" << endl; }
	};

	struct test_struct
	{
		void test_method() { cout << "7.���ýṹ��ĳ�Ա����" << endl; }
	};

	void test_ptr()
	{
		shared_ptr<test_struct> sp(new test_struct); 
		cout << "2.sp��Ȼshared_ptr���͵Ķ��󣬵������Ĺ��ܿ�����Ϊ��ָ��test_struct���͵�ָ��" << endl;
		test_struct ts(*sp);
		cout << "4.ts��test_struct���͵Ķ���" << endl;
		cout << "5.����������������ָ��ȥ����test_struct�����еĺ���" << endl;
		sp->test_method();
		//�������ָͨ��ȥ�����Ļ���ͬ������ȥ���ýṹ��ķ�����������������ָ������ɿ�����ȥ������Ҫ�Ĳ���

		cout << "�������ָͨ��ȥʵ�ֵĻ���" << endl;
		test_struct* ptr = new test_struct;
		ptr->test_method();
	}

	//������Ҳ�������Ϊ�ǹ��ܸ�ָ��������
}

//p18 function-like classes ���ܸ�����������࣬����std�еķº���
namespace p18
{

}

//p21 ����ģ��
namespace p21
{
	template<class T>
	const T& min(const T& a, const T& b)
	{
		return a < b ? a : b; //���ؽ�С�Ķ���
	}

	class stone
	{
	private:
		int _w, _h, _weight;
	public:
		stone(int w=0, int h=0, int we=0)
			:_w(w), _h(h), _weight(we) {}
		bool operator< (const stone& s) const { return this->_weight < s._weight; } //���������
		int get_stone_weight() const { return _weight; }
	};

	void test_function_template()
	{
		stone s1(1, 1, 2), s2(2, 2, 1), s3;
		s3 = min(s1, s2);
		cout << "���ú���ģ��Ƚ�stone��Ķ����и�С��һ�������� " << s3.get_stone_weight() << endl;
	}
}

//p22 member template ��Աģ��
namespace p22
{
	template<class T1, class T2>
	struct pair
	{
		T1 first;
		T2 second;
		pair():first(T1()),second(T2()){}
		pair(const T1& a, const T2& b):first(a),second(b){}

		//���ﰵָU1:T1 U2:T2
		template<class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

	};
}

//p23 specialization ģ���ػ�
namespace p23
{
	template<class Key>
	struct hash {};

	template<>
	struct hash<int> { int a; };
	template<>
	struct hash<char> { char c; };
}

//p24 partial specialization ģ��ƫ�ػ�
namespace p24
{
	template<class T1, class T2>
	class cl {};

	template<class T2>
	class cl<bool, T2> {};

	template<class T>
	class cla {};

	template<class U>
	class cla<U*> {}; //��Χƫ�ػ���Ĭ��ģ��T���������ͣ�U����ָָ������
}

//p25 template template parameter ģ��ģ����� ��������

//p27 variadic templates ����������ģ�����������
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
	//	print(1, "hello", 2, "world"); //����ʵ���˵ݹ��ӡ
	//}

	void tprintf(const char* format) // ��������
	{
		std::cout << format;
	}

	template<typename T, typename... Targs>
	void tprintf(const char* format, T value, Targs... Fargs) // �ݹ��κ���
	{
		for (; *format != '\0'; format++)
		{
			if (*format == '%')
			{
				std::cout << value;
				tprintf(format + 1, Fargs...); // �ݹ����
				return;
			}
			std::cout << *format;
		}
	}
}

//p28 reference��С��
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
		r = y; //r x ����5

		func1(x);
		func2(x);
	}
}

#include <list>
//p30 virtual pointer �� virtual table �麯����ʹ�÷���֮һ����̬
namespace p30
{
	//���ʵ����Ӵ�����
	class cl
	{
	public:
		virtual void func1() { cout << "���û���ĺ���"; }
	};

	class subcl:public cl
	{
	public:
		virtual void func1() { cout << "���ø���ĺ���"; }
	};

	class subsubcl :public subcl
	{
	public:
		void func1() { cout << "��������ĺ���"; }
	};

	list<cl*> mylist;
	//TODO ���ʵ�ֶ�̬
}

//p36

int main()
{
	
	return 0;
}

