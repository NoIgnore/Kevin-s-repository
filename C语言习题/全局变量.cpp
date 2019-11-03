#include<stdio.h>
int f(void);

int gAll=12;

int main(int argc, char const *argv[])
{
	printf("in %s gAll=%d\n", __func__, gAll);//两个下的线 ；printf的顺序为 1 
	f();
	printf("agn in %s gAll=%d\n", __func__, gAll);// 4 
	
	return 0;
}
int f(void)
{
	printf("in %s gAll=%d\n", __func__, gAll);//2 
	gAll +=2;
	printf("agn in %s gAll=%d\n", __func__, gAll);//3 
	return gAll;
}
