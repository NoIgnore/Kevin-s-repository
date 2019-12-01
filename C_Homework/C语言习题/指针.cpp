#include <stdio.h>
void f(int *p);
void g(int k);
int main(void)
{
	int i =6;
	printf("&i=%p\n", &i);
	f(&i);//*p传来的i已经变了！
	g(i); //g(26) 
	return 0;
}
void f(int *p)
{
	printf(" p=%p\n", p);
	printf("*p=%d\n", *p);
	*p = 26;//新赋予的值 
}

void g(int k)
{
	printf("k=%d\n",k);
}
