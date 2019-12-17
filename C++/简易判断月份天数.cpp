#include <iostream>
using namespace std;
int days(int y, int m)
{
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else if (m != 2)
	{
		return 31;
	}
	return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
}
int main()
{
	int y=2012;
	int m = 2;
	int a = days(y, m);
	cout << a;
	return 0;
}