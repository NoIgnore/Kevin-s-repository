#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
	srand(time(0));
	int number = rand()%1000+1;
	int count = 0;
	int a = 0;
	printf("���Ѿ������һ��1~1000����");
	do{
		printf("������1~1000������");
		scanf("%d", &a);
	    count ++;
	if ( a>number )
	{
		printf("��µ������ˡ�"); 
	} else if ( a <number )
	{
		printf("��µĵ���С�ˡ�");
	}
}while ( a!= number);
printf("̫���ˣ�������%d�ξͲµ��˴𰸡�\n", count);
    return 0;
}
