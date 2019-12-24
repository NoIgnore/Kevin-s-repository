#include<iostream>
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
int getsum(int y, int m)
{
	int sum = 0;
	return sum += (m == 1) ? 31 : getsum(y, m - 1) + days(y, m);
}
int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	cout << getsum(year, month - 1) + day;
	return 0;
}
/*
根据历法，凡是1、3、5、7、8、10、12月，每月31天；凡4、6、9、11月，每月30天；2月闰年29天，平年28天。
闰年判断方法是：
如果年号能被400整除，此年为闰年
如果年号能被4整除，而不能被100整除，此年为闰年；
否则不是闰年。

程序输入具体的年月日，输入为当年的第几天
例如：
输入：1994 09 11
输出：254
输入：2019 06 14
输出：165
*/
