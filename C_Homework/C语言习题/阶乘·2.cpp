#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int fact =1;
	int i = 1;
	for ( i=1; i<=n; i++)
	{
		fact*=i;
	}
//	��Ȼ��ʦ�Ĵ�������555555 
	printf("%d!=%d\n", n , fact);
	return 0;
 } 
