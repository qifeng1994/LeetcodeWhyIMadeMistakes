//要求用户输入三个数字，如果不是数字则提示用户重新输入

#include <iostream>
using namespace std;

int main()
{
    int range = 3;
    int number, total = 0;
    
    for ( int i = 0; i < range; i++)
    {
        cout << "continue input number" << endl;
        while (!(cin>>number))
        {
            cout << "reinput" << endl;
            cin.clear();
            while (cin.get()!='\n')
            {
                continue;
            }
        }
        total += number;
        
    }

    cout << "total number is " << total << endl;
}


