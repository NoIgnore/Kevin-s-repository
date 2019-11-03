#include<stdio.h>

int main(int argc, char const *argv[])
{
	int num ;
	printf("%dty%n\n",12345, &num );
	
	printf("%d\n", num );
	
	return 0;
} 
//发现这里的%n无法识别其前面统计的字符个数 
