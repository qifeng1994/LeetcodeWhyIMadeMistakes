//˽�м̳� 14.1�ĸĽ�
//ͨ��˽�м̳�������has-a�Ĺ�ϵ
//ͨ��ʹ�ð���������has-a��ϵ�����������Ҫ����ԭ����ı�����Ա������Ҫ���¶����麯������ʹ��˽�м̳�
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
	explicit Student(const string& s) :string(s), ArrayDb() {} //explicit��ʾ�������ֻ������Ϊ���캯����ʱ�����
	explicit Student(int n) :string("null"), ArrayDb(n) {}
	Student(const string& s, const ArrayDb& a) :string(s), ArrayDb(a) {}
	Student(const char* str, const double* pd, int n) :string(str), ArrayDb(pd, n) {} //??
	~Student() {}

	double Average()const;

	//��Ϊstudent���Ǵ�string���������ģ���˿���ͨ��ǿ������ת����student����ת��Ϊstring����,thisָ��ָ���������÷����Ķ���
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

void set(Student& sa, int n); //��14.1���û�б仯
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
		cout << endl << ada[i]; //���������أ���ӡ����scores
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
