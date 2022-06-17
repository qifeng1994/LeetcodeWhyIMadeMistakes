#include<iostream>
using namespace std;

//�����嵥18.6 18.7
template<typename T, typename F> //F��ָһ�ֺ�����ÿ�ε��ú�����������+1
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

void test_adapter() //��̬��count��ʵ������Σ���ַ��ͬ
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
//��װ����ʹ��
void fix_adapter()
{
	double y = 1.21;
	//����һ��������(signature)��double������double����ֵ�ĺ�������Ŀ����Ϊ��countֻ����һ��ʵ��
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

//���ں��滹�����˸��򵥵�д��

int main()
{
	// test_adapter();
	fix_adapter();
	return 0;
}