#include<iostream>
#include<fstream>
#include<cassert>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	string s1;
	cin >> s1;
	int length = s1.length();
	int dec = 0;
	int j = 0;
	for (int i = 0; i <length; i++)
	{
		j = (s1[i] == '1' ? 1 : 0);
		dec += (j == 1 ? pow(2, length - i - 1) : 0);
	}
	cout << dec << endl;
	return 0;
}