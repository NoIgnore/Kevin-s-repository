#include <stdio.h>
int main()
{
	char c[]="ghello";
	char *p=c;
//	printf("%c\n",*p);
//	printf("%s\n",p);
//	printf("%c\n", ++*p);
	printf("%s,%c,%s\n", p , *p ,p++);
//	while(*p){
//		putchar(*p);
//		p++;
//	}
	
	
	
	return 0;
}

