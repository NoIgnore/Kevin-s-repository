#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	char s[] = "hello";
	char *p = strchr(s, 'l');
	char c=*p;
	*p='\0';
	char *t = (char*)malloc(strlen(s)+1);
	strcpy(t,s);
	printf("%s\n",t);
	*p='l';
	printf("%s\n",s);
	free(t);
    return 0;
}
   
