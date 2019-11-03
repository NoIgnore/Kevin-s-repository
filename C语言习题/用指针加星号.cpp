//#include<stdio.h>
//#include<string.h>
//char mycpy(char dst[100], char src[100])
//{
//	int i=0;
//	char c;
//	int idx = 0;
//    while (src[idx]){
//	    c=src[idx];
//	    if( (idx>=2) && (idx<3) && (idx%2==0)){
//	    	c='*';
//		}
//		else if (idx>3 && idx%3==0){
//			c='*';
//		}
//	    dst[i]=c;
//	    i++;
//		idx++;
//    }
//	return *dst;
//}
//int main()
//{
//	char s1[100];
//	char s2[100];
//	scanf("%s", s2);
//	mycpy(s1,s2);
//	printf("%s", s1);
//	return 0;
//}//
#include <stdio.h> 
int main()
{
    char A[100];
    char *a = A;
    char B[100];
    char *b = B;
    int i = 0;
    gets(A);
    while(*a != '\0')
    {
        *b++ = *a++;
        i++;
        if(*a == '\0')
            break;
        if(i == 2)
        {
            *b = '*';
            b++;
            i = 0;
        }

    }
    *b = '\0';
    printf("%s\n", B);
    return 0;
}
