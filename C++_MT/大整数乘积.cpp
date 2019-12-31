#include<iostream>
#include<cstring>
#include<cstdlib>
/*
编写程序接受两个任意大的整数，返回两个整数之积（提示：大整数用字符串表示）。
例如输入：999 999
输出：998001
输入：0 9999999999999999
输出：0
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
	//....
	if (str1[0] == '0' || str2[0] == '0')
	{
		cout << "0" << endl;
		return;
	}
	int result[2 * maxn] = { 0 };
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			result[i + j] += a[i] * b[j];
		}
	}
	for (i = 0; i < (len1 + len2); i++)
	{
		if (result[i] > 9)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	for (i = len1 + len2; i >= 0; i--)
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