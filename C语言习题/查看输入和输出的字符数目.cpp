#include<stdio.h>

int main(int argc, char const *argv[])
{
	int num ;
	int i1=scanf("%i", &num);
	int i2=printf("%d\n", num);
	printf("%d:%d\n", i1,i2 );
	
	return 0;
} 
//发现这里的%n无法识别其前面统计的字符个数 
