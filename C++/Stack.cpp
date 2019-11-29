#include<iostream>//写个栈
using namespace std;
struct mystructure
{
	int data;
	mystructure* next;
};
int main() {
	mystructure* base = new mystructure;
	base->data = 0;
	base->next = nullptr;
	mystructure* top = new mystructure;
	top = base;
	cout << "please input the total number: n  =  ";
	int n;
	cin >> n;
	/*for (int i = 1; i <= n; i++) {
		mystructure* p = new mystructure;
		p->data = i;
		p->next = top;
		top = p;
	}*/
	for (int i = 1; i <= n; i++) {
		cout << "please input the element: " << endl;
		int j;
		cin >> j;
		mystructure* p = new mystructure;
		p->data = j;
		p->next = top;
		top = p;
	}
	/*for (int i = 1; i <= 5; i++) {
		cout << top->data << endl;
		top = top->next;
	}*/
	while (top->data != 0) {
		cout << top->data << endl;
		top = top->next;
	}
	return 0;
}
//please input the total number : n = 5
//please input the element :
//12
//please input the element :
//14
//please input the element :
//16
//please input the element :
//18
//please input the element :
//20
//20
//18
//16
//14
//12
//C++.exe(进程 29612)已退出，返回代码为: 0。
//按任意键关闭此窗口...