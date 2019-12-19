#include<iostream>//写个栈
using namespace std;
struct mystructure
{
	int data;
	mystructure* next;
};
void showelement(mystructure &a)
{
	mystructure* h = &a;
	while (h->data != 0) {
		cout << h->data << endl;
		h = h->next;
	}
	a = *h;
}
int main() {
	mystructure* base = new mystructure;
	base->data = 0;
	base->next = nullptr;
	mystructure* top = new mystructure;
	top = base;
	cout << "please input the total number: n  =  ";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "please input the element: " << endl;
		int j;
		cin >> j;
		mystructure* p = new mystructure;
		p->data = j;
		p->next = top;
		top = p;
	}
	mystructure j;
	j = *top;
	showelement(j);
	cout << j.data << endl;
	return 0;
}
//......................................................................................................
/*
please input the total number: n  =  2
please input the element:
1
please input the element:
2
2
1
0

Cplusplus项目.exe (进程 20864)已退出，返回代码为: 0。
按任意键关闭此窗口...
*/