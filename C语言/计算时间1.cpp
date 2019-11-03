#include <stdio.h>

int main()
{
	int t;
	int t1;
	int t2;
	int t3;
	int t4;
	int t5;
	scanf("%d %d", &t ,&t3);
	t1 =t/100;
	t2 =t%100;
	t4 =t1*60 + t2 + t3;
	t5 =(t4/60)*100 + t4%60;
	printf("%d\n", t5);
	return 0;
	
}
