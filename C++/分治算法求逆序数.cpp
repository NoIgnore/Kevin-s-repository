#include <iostream>
#include <algorithm>
using namespace std;
/*void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}*/
int merge(int* temp, int* arr, int x, int y, int m, int n)
{
	int nOrder = 0;
	int i = x, j = m;
	for (i = x; i <= y; ++i)
	{
		while (j <= n && arr[i] > arr[j]) {
			++j;
			nOrder += j - m;/*假设两个子数组已经排序，数组1在前，当前元素为arr[i]，数组2在后，
			当前元素为arr[j]，如果arr[i] > arr[j]，那么数组2中j和j之前的元素均与arr[i]构成一个逆序对*/
		    //因为47，48行无限递归到了最小的数组，所以最终已经是排好序的数组了
		}

	}
	int k = 0;
	i = x, j = m;
	while (i <= y && j <= n)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];//temp收录了较小值i
		else
			temp[k++] = arr[j++];//temp收录了较小值j
	}
	while (i <= y)
		temp[k++] = arr[i++]; /* Copy the remaining elements of left subarray
	   (if there are any) to temp*/
	while (j <= n)
		temp[k++] = arr[j++];/* Copy the remaining elements of right subarray
       (if there are any) to temp*/
	return nOrder;
}
int inversion_number(int* arr, int i, int j)
{
	if (i < j)
	{
		int mid = i + ((j - i) >> 1);//右移一位相当于除了2，这里mid相当于i+j/2
		//这是例如int i = 5的二进制是 00000101   i>>2 右移两位--> 00000001 (左边空出的补零)
		int v1 = inversion_number(arr, i, mid);
		int v2 = inversion_number(arr, mid + 1, j);
		int temp[10];
		int nValue = merge(temp, arr, i, mid, mid + 1, j);
		memcpy(arr + i, temp, sizeof(int) * (j - i + 1));
		/*memcpy指的是C和C++使用的内存拷贝函数，
		函数原型为void *memcpy(void *destin, void *source, unsigned n);
		函数的功能是从源内存地址的起始位置开始拷贝若干个字节到目标内存地址中，
		即从源source中拷贝n个字节到目标destin中。*/
		return v1 + v2 + nValue;
	}
	else
		return 0;
}
int main()
{
	int n;
	/*
	cout << "请输入数组长度： ";
	cin >> n;
	int* p = new int[n];
	cout << "请逐个输入数据：" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}*/
	n = 6;
	int p[6] = { 1,3,2,9,6,7 };
	cout << inversion_number(p, 0, n - 1) << endl;
	
	for (int i = 0; i < n; ++i)
	{
		cout << p[i];
	}
	return 0;
}
/*
请输入数组长度： 6
请逐个输入数据：
1 3 2 9 6 7
3

123679
C:\Users\12091\source\repos\C++项目\Debug\Project2.exe(进程 40756)已退出，返回代码为: 0。
按任意键关闭此窗口...*/
