#include<iostream>
#include<string>
#include<memory> //shared_ptr is a kind of smart pointer ?

using namespace std;

namespace s_ptr
{
    class Dog {
        string m_name;
    public:
        void bark() { cout << "Dog " << m_name << " rules!" << endl; }
        Dog(string name) { cout << "Dog is created: " << name << endl; m_name = name; }
        Dog() { cout << "Nameless dog created." << endl; m_name = "nameless"; }
        ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
    };

    void test1_s_ptr() //regular method to use shared_ptr
    {
        shared_ptr<Dog> p1(new Dog("Gunner"));
        {
            shared_ptr<Dog> p2 = p1;
            p2->bark();
            cout << p1.use_count(); //how many ptr points to the object
        }
        p1->bark();
    }

    void test2_s_ptr() // faster and safer
    {
        shared_ptr<Dog> p1 = make_shared<Dog>(new Dog("Gunner")); 
        p1->bark();
        (*p1).bark();
    }

    void test3_s_ptr() //Custom Deleter
    {
        shared_ptr<Dog> p1 = make_shared<Dog>(new Dog("Gunner")); //using default deleter: operator delete
        shared_ptr<Dog> p2 = shared_ptr<Dog>(new Dog("Tank"),
            [](Dog* p) {cout << "custom deleting. "; delete p; }
        );
        //shared_ptr<Dog> p3(new Dog[3]); dog[1] and dog[2] have memory leaks when delte
        shared_ptr<Dog> p4(new Dog[3], [](Dog* p) {delete[] p; }); //all 3 dogs will be deleted when p4 goes out of scope

    }


}