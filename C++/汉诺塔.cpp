#include<iostream>
using namespace std;
void hannuota(int n, char a, char b, char c) {
	if (n == 1) {
		cout << a << "->" << c << endl;
	}
	else
	{
		hannuota(n - 1, a, c, b);
		cout << a << "->" << c << endl;
		hannuota(n - 1, b, a, c);
	}
}
int main() {
	char d = 'a';
	char e = 'b';
	char f = 'c';
	int n = 3;
	hannuota(n, d, e, f);
	return 0;
}
/*
a->c
a->b
c->b
a->c
b->a
b->c
a->c

Cplusplus项目.exe (进程 1076)已退出，返回代码为: 0。
按任意键关闭此窗口...

*/