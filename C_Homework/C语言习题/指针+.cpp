#include <stdio.h>
int main()
{
	int a[]={1,6,9,4,5}, *p=a;
	p++;
	(*p)++;
	printf("%d\n", *p);
	printf("a[0]=%d, a[1]=%d , a[2]=%d", a[0],a[1],a[2]);
	return 0;
}
//这个表示 p指向了a[1] ， 然后a[1]=6 ,  6++=7 , 所以a[1]=7 
//输出结果为  1 7 9 
