#include<stdio.h>
int f(void);

int gAll=12;

int main(int argc, char const *argv[])
{
	f();
	f();
	f();
	return 0;
}
int f(void)
{
	static int all= 1;
	printf("in %s gAll=%d\n", __func__, all);
	all +=2;
	printf("agn in %s gAll=%d\n", __func__, all);
	return all;
} 
//静态本地变量实际上是特殊的全局变量 
