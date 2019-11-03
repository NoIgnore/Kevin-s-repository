#include<stdio.h>
void my_strcpy(char * destination,char * source);
int main()
{
	char a[100];
	char b[100];
	char *destination= a;
	char *source=b;
	gets(b);
	if(b == NULL){
	   printf("error");
	}
	my_strcpy(destination, source);
	printf("%s", destination);
	return 0;
} 
void my_strcpy(char * destination,char * source)
{
	while( *source!=' ' ){
		*destination++ = *source++;
	}
}

