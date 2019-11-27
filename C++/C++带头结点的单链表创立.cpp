#include <iostream>
using namespace std;
struct lianbiao
{
	int value;
	lianbiao* next;
};

int main()
{
	lianbiao* touzhizhen = new lianbiao;
	touzhizhen->value = 100;
	touzhizhen->next = nullptr;
	lianbiao* weizhizhen = new lianbiao;
	weizhizhen->value = 1;
	weizhizhen->next = nullptr;
	touzhizhen->next = weizhizhen;
	for (int i = 2; i <= 10; i++) {
		lianbiao* p = new lianbiao;
		p->value = i;
		p->next = nullptr;
		weizhizhen->next = p;
		weizhizhen = p;
	}
	lianbiao* a = new lianbiao;
	a = touzhizhen;
	for (int i = 1; i <= 11; i++) {
		cout << a->value << endl;
		a = a->next;
	}
	cout << "List..." << endl;
	return 0;
}
// 100
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// List...

// C:\Users\12091\source\repos\C++项目\Debug\C++项目.exe (进程 66000)已退出，返回代码为: 0。
// 按任意键关闭此窗口...
