#include<stdio.h>
#include<string.h>
void my_strcpy(char * destination,char * source);

int main(int argc, char const *argv[])
{
	char destination[100];
	char source[100];
	scanf("%s",&source);
	if(destination == NULL || source == NULL){
	   printf("error");
	}else {
		my_strcpy(destination,source);
    	printf("%s", destination);
	} 
	
	return 0;
}
void my_strcpy(char * dst , char * src)
{
	//int idx = 0;
//	while (src[idx] ){
//		dst[idx]=src[idx];
//		idx++;
//	}
//	dst[idx]='\0';数组的做法 
//  return dst;
    char *ret = dst;
    while (*ret++ = *src++);
	*ret = '\0';
	//指针的做法 
	dst = ret; 	
} 
