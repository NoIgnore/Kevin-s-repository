#include<iostream>
#include<cstring>
#include<cstdlib>
/*
编写程序接受两个任意大的整数，返回两个整数之差，（提示：大整数用字符串表示）。
输出格式：如果结果为正，在结果前用"+"表示，如果为负数则加上"-";
如果结果的位数小于输入整数的位数，则在结果前面补零直到和位数最大的输入数位数一致;
如果两个数相等直接输出0
例如输入：22345678900 12345678900
输出：+10000000000
输入：100 1010
输出：-0910
输入：12345 12345
输出：0
*/
#include<iostream>

#include<cstring>

#include<cstdlib>

#define maxn 1000

using namespace std;

int a[maxn], b[maxn];

bool compare(const char str1[], const char str2[])

{

	if (strlen(str1) > strlen(str2))

		return true;

	if (strlen(str1) == strlen(str2))

		return strcmp(str1, str2) > 0;

	return false;

}

void sub(char str1[], char str2[])

{

	int i = 0, j = 0;

	int len1 = strlen(str1);

	int len2 = strlen(str2);

	int maxLen = len1 > len2 ? len1 : len2;

	for (i = len1 - 1, j = 0; i >= 0; i--)

		a[j++] = str1[i] - '0';

	for (i = len2 - 1, j = 0; i >= 0; i--)

		b[j++] = str2[i] - '0';
	//...............................................................................
	int bit = 0;
	for (int i = 0; i < maxn; i++)
	{
		a[i] -= bit;
		if (a[i] < b[i])
		{
			a[i] += 10;
			bit = 1;
		}
		else
			bit = 0;
		b[i] = a[i] - b[i];
	}
	i = maxLen-1;
	if (i >= 0)
		for (; i >= 0; i--)
			cout << b[i];
	else
		cout << 0;
	cout << endl;
	//...............................................................................
}

int main(void)

{

	char str1[maxn], str2[maxn];

	cin >> str1 >> str2;

	if (strcmp(str1, str2) == 0)

	{

		cout << 0;

	}

	else if (compare(str1, str2))

	{

		cout << "+";

		sub(str1, str2);

	}

	else

	{

		cout << "-";

		sub(str2, str1);

	}

	return 0;

}