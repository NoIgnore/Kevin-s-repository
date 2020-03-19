#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int m;
int up_or_low = 0;
void transform(char s[], int n[])
{
	int i;
	printf("输入连续的小写或大写字母:");
	cin >> (s);
	m = strlen(s);
	for (i = 0; i < m; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			n[i] = s[i] - 'a';
		}
		else if (s[i] >= 'A' && s[i] < 'Z')
		{
			up_or_low = 1;
			n[i] = s[i] - 'A';
		}
		else
		{
			printf("输入有误");
			return;
		}
	}
}
void endecryp(int input[], int a, int b, int output[])
{
	int i;
	int j = up_or_low ? 65 : 97;
	for (i = 0; i < m; i++)
	{
		output[i] = (a * input[i] + b) % 26;
		cout << (char)(j + output[i]);
	}
	cout << endl;
}
int main()
{
	char s[100]; int n[100], d[100];
	transform(s, n);
	cout << "加密：";
	endecryp(n, 11, 6, d);//加密函数y=11x+6mod26
	cout << "解密：";
	endecryp(d, 19, 16, n);//解密函数x=19y+16mod26
	cout << endl;
	cout << "加密：";
	endecryp(n, 7, 3, d);//加密函数y=7x+3mod26
	cout << "解密：";
	endecryp(d, 15, 7, n);//解密函数x=15y+7mod26
	return 0;
}
//输入连续的小写或大写字母:ajourneyofathousandmilesbeginswithasinglestep
//加密：gbesltykejghfeswgtniqxywryuqtwoqhfgwqtuxywhyp
//解密：ajourneyofathousandmilesbeginswithasinglestep
//
//加密：doxnsqfpxmdgaxnzdqyjhcfzkfthqzbhgadzhqtcfzgfe
//解密：ajourneyofathousandmilesbeginswithasinglestep

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[122];
//	char b[26];
//	int n;
//	float num, num2;
//	while (gets_s(a) != NULL)
//	{
//		int s[100] = { 0 };
//		for (int x = 0; x < 26; x++)
//		{
//			int c = 0;
//			n = strlen(a);
//			num2 = (float)n;
//			b[x] = x + 97;
//			for (int i = 0; i < n; i++)
//			{
//				if (b[x] == a[i] || b[x] == a[i] + 32)
//				{
//					c++;
//					s[x] = c;
//				}
//
//			}
//			if (s[x] >= 1)
//			{
//				printf("%c: %d ", b[x], s[x]);
//				num = (float)s[x];
//				printf("%.3f\n", num / num2);
//			}
//		}
//		printf("\n");
//		printf("tatal = %.1f", num2);
//	}
//	
//	return 0;
//}