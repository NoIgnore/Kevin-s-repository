#include<stdio.h>
//#include<string.h>
int main()
{
	char c[100];
	int i;
	int counta=0,countd=0;
	scanf("%s",&c);
//	gets(c);
	for(i=0;i<100;i++){
		if (c[i]=='a'){
			counta++;
			continue;
		}
		if (c[i]=='d'){
			countd++;
			continue;
		}
	}
	printf("a:%d,d:%d", counta,countd);
	return 0;
}
