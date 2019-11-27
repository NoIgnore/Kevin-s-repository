#include<iostream>
using namespace std;
int minvalue(int i, int j, int** m, int* p) {
	if (m[i][j]>0) {
		return m[i][j];
	}
	if (i == j) {
		return 0;
	}
	int min;
	min = minvalue(i, i, m, p) + minvalue(i + 1, j, m, p) + p[i-1]*p[i]*p[j];
	for (int k = i + 1; k < j; k++) {
		int comparevalue;
		comparevalue = minvalue(i, k, m, p) + minvalue(k + 1, j, m, p) + p[i - 1] * p[k] * p[j];
		if (comparevalue < min) {
			min = comparevalue;
		}
	}
	m[i][j] = min;
	return min;
}
int main() {
	int n,o,g;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}//输入{50,10,40,30,5}
	int** m = new int* [n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n];//二维数组：每一行都分配七列
	}
	for (int i = 0; i < n; i++)//初始化所有值，全部归零
	{
		for (int j = 0; j < n; j++)
		{
			m[i][j] = 0;
		}
	}
	o = 1;
	g = 5;
	cout << minvalue(o, g - 1, m, p);
}
/*{50,10,40,30,5};
矩阵的最少计算次数为：10500
矩阵最优计算次序为：
Multiply A3,3 and A4,4
Multiply A2,2 and A3,4
Multiply A1,1 and A2,4
----------------------解释起来就是(A(B(CD)))
C++项目.exe (进程 15948)已退出，返回代码为: 0。
按任意键关闭此窗口...
*/