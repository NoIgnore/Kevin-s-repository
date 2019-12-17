#include<iostream>
#include <set>
using namespace std;
int main()
{
	int b, a;
	a = 3;
	b = 4;
	int c;
	c = a ^ b;//先将a->011,b->100,所以异或出来的c=111,输出结果为7
	cout << c;
	return 0;
}
/*7
Project1.exe (进程 10268)已退出，返回代码为: 0。
按任意键关闭此窗口...*/