#include<iostream>//写个队列array
using namespace std;
int main() {
	int n;
	cin >> n;
	int* a = new int[n+1];
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << endl;
	}
	delete[] a;
	return 0;
}
/*
int *p=new int[n]; //定义一个整型指针变量p，new动态分配存放一个整数的内存空间，将首地址赋给指针变量p；
运算符delete用于释放分配内存的基本形式：
delete[] p;（首地址已经存放在指针变量p中)
*/