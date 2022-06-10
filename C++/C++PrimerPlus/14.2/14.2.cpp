//私有继承 14.1的改进
//通过私有继承来建立has-a的关系
//通常使用包含来建立has-a关系，如果新类需要访问原有类的保护成员，或需要重新定义虚函数，则使用私有继承
#include <iostream>
#include <string>
#include <valarray>
using namespace std;

class Student :private string, private valarray<double>
{
private:
	typedef valarray<double> ArrayDb;
	ostream& arr_out(ostream& os)const;
public:
	Student() :string("null student"), ArrayDb() {}
	explicit Student(const string& s) :string(s), ArrayDb() {} //explicit表示这个函数只能在作为构造函数的时候调用
	explicit Student(int n) :string("null"), ArrayDb(n) {}
	Student(const string& s, const ArrayDb& a) :string(s), ArrayDb(a) {}
	Student(const char* str, const double* pd, int n) :string(str), ArrayDb(pd, n) {} //??
	~Student() {}

	double Average()const;

	//因为student类是从string类派生来的，因此可以通过强制类型转换将student对象转换为string对象,this指针指向用来调用方法的对象
	const string& Name()const { return (const string&)*this; } 
	double& operator[](int i) { return ArrayDb::operator[](i); } //
	double operator[](int i)const { return ArrayDb::operator[](i); } //

	friend istream& operator>>(istream& is, Student& stu);
	friend istream& getline(istream& is, Student& stu);
	friend ostream& operator<<(ostream& os, const Student& stu);


};

double Student::Average()const
{
	if (ArrayDb::size()>0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

ostream& Student::arr_out(ostream& os)const
{
	if (ArrayDb::size() > 0)
	{
		for (int i = 0; i < ArrayDb::size(); ++i)
			os << ArrayDb::operator[](i) << " ";
	}
	else
		os << " empty array ";
	return os;
}

istream& operator>>(istream& is, Student& stu)
{
	is >> (string&)stu; //
	return is;
}

istream& getline(istream& is, Student& stu)
{
	getline(is, (string&)stu); //
	return is;
}

ostream& operator<<(ostream& os, const Student& stu)
{
	os << "scores for " << (string&)stu << ": \n";
	stu.arr_out(os); 
	return os;
}

void set(Student& sa, int n); //与14.1相比没有变化
int main()
{
	Student ada[3] = { Student(5),Student(5),Student(5) };
	for (int i = 0; i < 3; ++i)
		set(ada[i], 5);

	cout << "\nStudent List:\n";
	for (int i = 0; i < 3; ++i)
		cout << ada[i].Name() << endl;

	cout << "\nresults:";
	for (int i = 0; i < 3; ++i)
	{
		cout << endl << ada[i]; //操作符重载，打印出了scores
		cout << "average: " << ada[i].Average() << endl;
	}
	cout << "done. \n";
	return 0;
}

void set(Student& sa, int n)
{
	cout << "please enter the student name: ";
	getline(cin, sa);
	cout << "please enter " << n << " scores:\n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}
