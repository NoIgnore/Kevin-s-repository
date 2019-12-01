#include <stdio.h>
int main()
{
	int mask = 10000,x=13425;
	do{
		int d= x/mask;
		x%=mask; //5%=1 -------> 5对1取余等于零！！！！ 
		//所以最后一行 5  0  0 
		mask /= 10;
		printf("d=%d ,x=%d,mask=%d\n", d , x , mask);
	} while (x>0);
	printf("\n");
	return 0; 
 } 
