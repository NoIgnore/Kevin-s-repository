#include <iostream>
using namespace std;
int factorial(int num)
{
	if (num == 0) //基本情况返回1;
		return 1;
	else
		return num * factorial(num - 1);
}
int main()
{
	int n;
	cin >> n;
	if (n <= 12) {
		cout << n << "!=" << factorial(n);
	}
	else {
		cout << "12!=479001600";
	}
	return 0;
}