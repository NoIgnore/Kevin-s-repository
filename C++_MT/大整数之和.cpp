#include<iostream>
#include<cstring>
#include<cstdlib>
/*
编写程序接受两个任意大的整数，返回两个整数之和，（提示：大整数用字符串表示）。
例如输入：999999999 999999999
输出：1999999998
*/
#define maxn 1000
using namespace std;
int a[maxn], b[maxn];
void mul(char str1[], char str2[])
{
	int i = 0, j = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (i = len1 - 1, j = 0; i >= 0; i--)
		a[j++] = str1[i] - '0';
	for (i = len2 - 1, j = 0; i >= 0; i--)
		b[j++] = str2[i] - '0';
	//将字符串转移到数组中，以方便计算 ，注意是倒叙存储
	//即字符串123存为321，为的是将低位放在前面方便计算 
	//....
	if (str1[0] == '0' && str2[0] == '0')
	{
		cout << "0" << endl;
		return;
	}
	int max_len = 0;
	max_len = len1 > len2 ? len1 : len2;
	int result[2 * maxn] = { 0 };
	int k, h1, h2;
	for (i = 0, j = 0, k = 0; k < max_len + 1;)
	{
		if (j < len2)
		{
			h2 = b[j++];
		}
		else h2 = 0;
		if (i < len1)
		{
			h1 = a[i++];
		}
		else h1 = 0;
		result[k++] = h1 + h2;
	}
	for (i = 0; i < max_len ; i++)
	{
		if (result[i] > 9)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	for (i = max_len; i >= 0; i--)
	{
		if (result[i] == 0) continue;
		else break;
	}
	for (; i >= 0; i--)cout << result[i];
	//....
}

int main(void)
{
	char str1[maxn], str2[maxn];
	cin >> str1 >> str2;
	mul(str1, str2);
	return 0;
}