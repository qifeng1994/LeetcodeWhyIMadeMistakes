//P10
//static例子，银行账户
//class Account
//{
//public:
//	static double m_rate;
//	static void set_rate(const double& x) { m_rate = x; } //为什么要写double&
//};
//
//double Account::m_rate = 8.0; //静态数据必须定义，也可以不赋值具体的数字
//
//int main()
//{
//	Account::set_rate(5.0); //通过class name调用static函数
//
//	Account a;
//	a.set_rate(7.0); //通过object调用static函数
//}

//类模板，使用的时候要指定具体类型
//函数模板，使用的时候不用指定类型，因为系统会根据参数类型推断