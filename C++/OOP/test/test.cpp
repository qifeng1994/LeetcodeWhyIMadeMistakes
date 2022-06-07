////不带指针的类多半不用析构函数
//class complex
//{
//private:
//	double re, im;
//
//	//friend complex& __doapl(complex*, const complex&); //友元函数可以访问私有成员//友元函数要声明成private吗？
//public:
//	complex(double r = 0, double i = 0) :re(r), im(i)
//	{} //这种写法的构造函数效率会更高
//
//	double real() const { return re; } 
//	double imag() const { return im; }
//
//	//complex& 按引用传递参数,返回值
//	//成员函数的操作符重载
//	inline complex&
//		operator += (const complex & r)
//	{
//		return __doapl(this, r);
//	}
//
//	inline complex&
//		__doapl(complex* ths, const complex& r)
//	{
//		ths->re += r.re;
//		ths->im += r.im;
//		return *ths;
//	}
//
//};
//
//complex c1(2, 1); //最常见的方法
//complex c2; //采用默认的初始值（0，0）
//complex* p = new complex(4); //通过指针创建动态对象
//
////非成员函数的操作符重载 使用例：cout<<c1;
////
//ostream&
//operator << (ostream& os, const complex& x)
//{
//	return os << '(' << x.real() << ',' << x.imag() << ')';
//}