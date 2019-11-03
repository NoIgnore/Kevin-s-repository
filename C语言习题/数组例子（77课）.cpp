#include <stdio.h>
int main(void)
{
//	const int number = 10;
	int x;
	int count [10];
	int i;
	for ( i=0;i<10;i++){
		count[i]=0;
	}
	scanf("%d", &x);
	while (x!= -1){
	    if (x>=0 && x<=9){
		    count[x]++; 
	    }
	    scanf("%d", &x);
    }
	for (i=0;i<10;i++){
		printf("%d出现了%d次\n" , i, count[i]);
	}
	return 0;
}
