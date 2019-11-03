#include <stdio.h> 
int main()
{
	int x;
//	scanf("%d", &x);
	x =13425;
	do {
		int d= x%10;
		printf("%d", d);//：如果%d后面有空格，最后一个数也会打出空格
		if (x>9){
			printf(" ");
		} 
		x/=10;
	} while (x>0);
	return 0;
}
