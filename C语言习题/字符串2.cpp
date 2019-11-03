#include <stdio.h>
//#include <string.h>
int main()
{
// 	char word[] = {'G','F','\0'};
    char *str ="Hello";
//    char word[] = "Hello";
//    char line[10]="Hello";
    str[0]='b';
    printf("%c", str[0]);
 	return 0;
}
