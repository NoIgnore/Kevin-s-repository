#include <stdio.h>
int main()
{
	int year, i;
	scanf("%d", &year);
	if(year < 2001 || year > 2100)    //* 21���͹�100�꣬2001��Ϊ��ʼ�� 
		printf("Invalid year!\n");
	else {
		for(i = 2001; i <= year; ++i) {
			if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
				printf("%d\n", i);
		}
	}
	return 0;
 } 
