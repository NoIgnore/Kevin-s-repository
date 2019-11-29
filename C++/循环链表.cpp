#include<iostream>
using namespace std;
struct jgt
{
	int live = 1;
	int id = 0;
	jgt* next=nullptr;
};
int main() {
	int p=10;
	int c;
	//cin >> p;
	//cin >> c;
	jgt* tou = new jgt;
	jgt* wei = new jgt;
	tou->id = 1;
	tou->next = wei;
	wei->id = 2;
	for (int i = 3; i <= p; i++) {
		jgt* xin = new jgt;
		xin->id = i;
		wei->next = xin;
		wei = xin;
	}
	wei->next = tou;
	jgt* xin1 = new jgt;
	xin1 = tou;
	for (int i = 1; i <= p+1; i++) {
		cout << xin1->id << endl;
		xin1 = xin1->next;
	}
	return 0;
}
/*
1
2
3
4
5
6
7
8
9
10
1

C++项目.exe (进程 27676)已退出，返回代码为: 0。
按任意键关闭此窗口...
*/