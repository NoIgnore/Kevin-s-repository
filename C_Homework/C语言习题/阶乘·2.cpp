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
//	果然老师的代码更简便555555 
	printf("%d!=%d\n", n , fact);
	return 0;
 } 
