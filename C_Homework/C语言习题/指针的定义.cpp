#include<stdio.h>
int main()
{
	int x,y=10,
	*p=&y;
	x=*p;
	printf("%d", x);
}
/* 
#include<stdio.h>
int main()
{
	int x,*p;
	p=&x;
	x=10;
	printf("%d", *p);
}
*/ 
