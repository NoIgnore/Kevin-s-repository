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
	endecryp(n, 11, 6, d);//加密函数y=11x+6mod26
	endecryp(d, 19, 16, n);//解密函数x=19y+16mod26
	return 0;
}
//输入连续的小写或大写字母:ajourneyofathousandmilesbeginswithasinglestep
//gbesltykejghfeswgtniqxywryuqtwoqhfgwqtuxywhyp