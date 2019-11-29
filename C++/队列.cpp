#include<iostream>//写个队列queue
using namespace std;
struct mystructure
{
	int data;
	mystructure* next;
};
int main() {
	mystructure* head = new mystructure;
	head->data = 123;
	head->next = NULL;
	mystructure* tail = new mystructure;
	tail = head;
	cout << "please input the total number: n  =  ";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		mystructure* newpoint = new mystructure;
		cout << "please input the element: " << endl;
		int j;
		cin >> j;
		newpoint->data = j;
		newpoint->next = NULL;
		tail->next = newpoint;
		tail = newpoint;
	}
	while (head->next != NULL)
	{
		cout << head->next->data << endl;
		head = head->next;
	}
	if (head == tail) {
		cout << "head = tail" << endl;
	}
	return 0;
}
//please input the total number : n = 5
//please input the element :
//12
//please input the element :
//13
//please input the element :
//14
//please input the element :
//15
//please input the element :
//16
//12
//13
//14
//15
//16
//head = tail
//C++.exe(进程 48184)已退出，返回代码为: 0。
//按任意键关闭此窗口...