//虽然程序打一遍之后懂了，但是感觉如果自己能默写出来就好了:D
//通过建立私有成员来建立has-a的关系
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
    ostream& arr_out(ostream& os)const; //打印score
public:
    Student() :name("null student"), scores() {}
    explicit Student(const string& s) :name(s), scores() {} //explicit表示这个函数只能在作为构造函数的时候调用
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
    stu.arr_out(os); //牛逼啊
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
        cout << endl << ada[i]; //操作符重载，打印出了scores
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "done. \n";
    return 0;

}

