#include <stdio.h>
int main ()
{
	int x,a=1;
	printf("n=");
	scanf("%d", &x);
	while (x>0)
	{
		a*=x;
		x=x-1;
	 } 
	 printf("n!=%d\n", a );
	 return 0;
}
