//��Ȼ�����һ��֮���ˣ����Ǹо�����Լ���Ĭд�����ͺ���:D
//ͨ������˽�г�Ա������has-a�Ĺ�ϵ
#include <iostream>
#include <string>
#include <valarray>
using namespace std;

class Student
{
private:
    typedef valarray<double> ArrayDb;
    string name;
    ArrayDb scores;
    ostream& arr_out(ostream& os)const; //��ӡscore
public:
    Student() :name("null student"), scores() {}
    explicit Student(const string& s) :name(s), scores() {} //explicit��ʾ�������ֻ������Ϊ���캯����ʱ�����
    explicit Student(int n) :name("null"), scores(n) {}
    Student(const string& s, const ArrayDb& a) :name(s), scores(a) {}
    Student(const char* str, const double* pd, int n) :name(str), scores(pd, n) {} //??
    ~Student() {}

    double Average()const;
    const string& Name()const { return name; } //get name
    double& operator[](int i) { return scores[i]; }//get scores[i]
    double operator[](int i)const { return scores[i]; } //get scores[i]

    friend istream& operator>>(istream& is, Student& stu);
    friend istream& getline(istream& is, Student& stu);
    friend ostream& operator<<(ostream& os, const Student& stu);

};

double Student::Average()const
{
    if (scores.size() > 0)
    {
        return scores.sum() / scores.size();
    }
    else
        return 0;
}

ostream& Student::arr_out(ostream& os)const
{
    if (scores.size()>0)
    {
        for (int i=0;i<scores.size();++i)       
            os << scores[i] << " ";    
    }
    else
        os << " empty array ";
    return os;
}

istream& operator>>(istream& is, Student& stu)
{
    is >> stu.name;
    return is;
}

istream& getline(istream& is, Student& stu)
{
    getline(is, stu.name);
    return is;
}

ostream& operator<<(ostream& os, const Student& stu)
{
    os << "scores for " << stu.name << ": \n";
    stu.arr_out(os); //ţ�ư�
    return os;
}


void set(Student& sa, int n);
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

