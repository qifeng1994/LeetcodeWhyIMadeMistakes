
#include <iostream>
#include <string>
#include <algorithm>
#include<vector>

using namespace std;
int main() {
	vector<int>v = { 1,2,3,4 };
	cout << "first address " << &v[0] << endl;
	for (int i = 0; i < 4; i++)
	{
		v[i] ++;
	}

	for (int i : v)
	{
		cout << "index = " << &i << " value = " << i << endl;
	}

	return 0;
}