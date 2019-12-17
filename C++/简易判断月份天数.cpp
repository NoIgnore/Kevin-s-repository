#include <iostream>
using namespace std;
int days(int y, int m)
{
	int a = 0;
	int b = 0;
	int c;
	(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? a = 1 : a = 0;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		b = 1;
	}
	else if (m == 2)
	{
		return c = (a == 1) ? 29 : 28;
	}
	return c = (b == 1) ? 31 : 30;
}
int main()
{
	int y=2008;
	int m = 3;
	int a = days(y, m);
	cout << a;
	return 0;
}