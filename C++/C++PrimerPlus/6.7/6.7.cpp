//Ҫ���û������������֣����������������ʾ�û���������

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


