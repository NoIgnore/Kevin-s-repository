#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
	srand(time(0));
	int number = rand()%1000+1;
	int count = 0;
	int a = 0;
	printf("我已经想好了一个1~1000的数");
	do{
		printf("请猜这个1~1000的数：");
		scanf("%d", &a);
	    count ++;
	if ( a>number )
	{
		printf("你猜的数大了。"); 
	} else if ( a <number )
	{
		printf("你猜的的数小了。");
	}
}while ( a!= number);
printf("太好了，你用了%d次就猜到了答案。\n", count);
    return 0;
}
