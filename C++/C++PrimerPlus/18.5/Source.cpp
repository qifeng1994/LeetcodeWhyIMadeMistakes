#include<iostream>
using namespace std;

//程序清单18.6 18.7
template<typename T, typename F> //F暗指一种函数，每次调用函数，计数器+1
T use_f(T v, F f)
{
	static int count = 0;
	count++;
	cout << "use_f count = " << count
		<< ", &count = " << &count << endl;
	return f(v);
}

class Fp
{
private:
	double z_;
public:
	Fp(double z = 1.0) :z_(z) {}
	double operator()(double p) { return z_ * p; }
};

class Fq
{
private:
	double z_;
public:
	Fq(double z = 1.0) :z_(z) {}
	double operator()(double q) { return z_ + q; }
};

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

void test_adapter() //静态的count被实例化多次，地址不同
{
	double y = 1.21;
	cout << "function pointer dub:\n";
	cout << " " << use_f(y, dub) << endl;
	cout << "function pointer square:\n";
	cout << " " << use_f(y, square) << endl;

	cout << "function object Fp:\n";
	cout << " " << use_f(y, Fp(5.0)) << endl; //5.0*1.21
	cout << "function object Fq:\n";
	cout << " " << use_f(y, Fq(5.0)) << endl; //5.0+1.21

	cout << "lambda expression 1:\n";
	cout << " " << use_f(y, [](double u) {return u * u; }) << endl; //1.21*1.21
	cout << "lambda expression 2:\n";
	cout << " " << use_f(y, [](double u) {return u + u / 2.0; }) << endl;
}

#include<functional>
//包装器的使用
void fix_adapter()
{
	double y = 1.21;
	//定义一个特征标(signature)是double参数，double返回值的函数对象。目的是为了count只创建一个实例
	function<double(double)>ef1 = dub;
	function<double(double)>ef2 = square;
	function<double(double)>ef3 = Fp(5.0);
	function<double(double)>ef4 = Fq(5.0);
	function<double(double)>ef5 = [](double u) {return u * u; };
	function<double(double)>ef6 = [](double u) {return u + u / 2.0; };

	cout << "function pointer dub:\n";
	cout << " " << use_f(y, ef1);
	cout << "function pointer square:\n";
	cout << " " << use_f(y, ef2) << endl;

	cout << "function object Fp:\n";
	cout << " " << use_f(y, ef3) << endl; //5.0*1.21
	cout << "function object Fq:\n";
	cout << " " << use_f(y, ef4) << endl; //5.0+1.21

	cout << "lambda expression 1:\n";
	cout << " " << use_f(y, ef5) << endl; //1.21*1.21
	cout << "lambda expression 2:\n";
	cout << " " << use_f(y, ef6) << endl;
}

//本节后面还介绍了更简单的写法

int main()
{
	// test_adapter();
	fix_adapter();
	return 0;
}