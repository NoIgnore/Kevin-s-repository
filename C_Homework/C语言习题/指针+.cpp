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
//�����ʾ pָ����a[1] �� Ȼ��a[1]=6 ,  6++=7 , ����a[1]=7 
//������Ϊ  1 7 9 
