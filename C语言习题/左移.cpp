#include<stdio.h>

int main(int argc, char const *argv[])
{
	unsigned char c= 0xA5;
	printf("   c=%hhx\n", c);
	printf("c<<2=%d\n",c<<2);//%hhx�ǵ���16��������� 
//	printf("-c=%hhx\n", (char)-c);
	
	return 0;
}

