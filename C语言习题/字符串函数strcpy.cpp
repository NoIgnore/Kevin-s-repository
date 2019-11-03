#include<stdio.h>
#include<string.h>
char*mycpy(char*dst, const char *src)
{
	//int idx = 0;
//	while (src[idx] ){
//		dst[idx]=src[idx];
//		idx++;
//	}
//	dst[idx]='\0';数组的做法 
//  return dst;
    char *ret = dst;
    while (*dst++ = *src++);
	*dst = '\0';
	//指针的做法 
	return ret; 
	
} 
int main(int argc, char const *argv[])
{
	char s1[] = " ";
	char s2[] ="abhjhgjhjh";
	mycpy(s1,s2);
	printf("%s", s1);
	return 0;
}

