/*
计算并返回 x 的平方根(x由键盘输入)，返回类型是整数，结果只保留整数的部分，小数部分舍去。
如果 x 是负数，输出：error

示例 1
输入: -1
输出: error

示例 2
输入: 4
输出: 2

示例 3
输入: 8
输出: 2

说明: 8 的平方根是 2.82842...,
	 由于返回类型是整数，小数部分将被舍去。
*/
#include<iostream>

using namespace std;

int main()

{
	//...
	int x; 
	int y; 
	cin >> x; 
	if (x <= 0)
	{
		cout << "error" << endl;
		return 0;
	}
	for (y = 1; y * y < x; y++); 
	if (y * y == x) cout << y << endl;
	if (y * y > x) cout << y - 1 << endl;
	//...
	return 0;

}