#include<stdio.h>

int main(int argc, char const *argv[])
{
	int num ;
	printf("%dty%n\n",12345, &num );
	
	printf("%d\n", num );
	
	return 0;
} 
//���������%n�޷�ʶ����ǰ��ͳ�Ƶ��ַ����� 
