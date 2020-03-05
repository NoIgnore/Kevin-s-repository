#include<stdio.h>
#include<string.h>
int main()
{
	char a[122];
	char b[26];
	int n;
	while (gets_s(a) != NULL)
	{
		int s[100] = { 0 };
		for (int x = 0; x < 26; x++)
		{
			int c = 0;
			n = strlen(a);
			b[x] = x + 97;
			for (int i = 0; i < n; i++)
			{
				if (b[x] == a[i] || b[x] == a[i] + 32)
				{
					c++;
					s[x] = c;
				}

			}
			if (s[x] >= 1)
			{
				printf("%c: %d\n", b[x], s[x]);
			}
		}
		printf("\n");
	}
	return 0;
}

