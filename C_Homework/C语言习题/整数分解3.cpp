#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);
	//x=....
	int mask=1;
	int t =x ;
	while (t>9){
		t/=10;
		mask*=10;
	}
	printf("x=%d, mask=%d\n", x ,mask);
	
	while(x>0)	{
	int d=x%10;
		printf("%d",d);
		x /= 10; 
		if (x>0){
			printf(" ");
	}
}
	return 0;
 } 
