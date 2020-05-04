#include<iostream>
#include<fstream>
#include<cassert>
#include<string>
#include<math.h>
using namespace std;
struct binstack 
{
	int s;
	binstack* next;
};
int main()
{
	//bin to dec
	string s1 = "1111";//dec=15
	int length = s1.length();
	int dec = 0;
	int j = 0;
	for (int i = 0; i <length; i++)
	{
		j = (s1[i] == '1' ? 1 : 0);
		dec += (j == 1 ? pow(2, length - i - 1) : 0);
	}
	cout << dec << endl;
	//dec to bin
	int test = 255;//bin=11111111
	binstack* k1 = new binstack;
	binstack* k2 = k1;
	while (test != 0)
	{
		binstack* kk = new binstack;
		kk->s = test % 2;
		kk->next = k2;
		k2 = kk;
		test = test / 2;
	}
	binstack* k3 = k2;
	string s2;
	while (k3 != k1) 
	{
		s2 += to_string(k3->s);
		k3 = k3->next;
	}
	cout << s2 << endl;
	return 0;
}