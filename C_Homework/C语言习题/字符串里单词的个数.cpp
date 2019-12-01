//#include<stdio.h> 
//int main()
//{
//	int c=0;
//	char zf[256];
//	scanf("%s", zf);
//	for(int i=0;i<256;i++){
//		if(zf[i] != ' '  && zf[i] != '0'){
//			c++;
//		}
//	}
//	printf("%d",c);
//    return 0;
//}
#include <stdio.h>
#include <string.h>
//输入一行字符，统计其中有多少单词，单词之间用空格分隔开
int main()
{
   int i,num=0,word=0;
   char zf[256];
   char c;
   gets(zf);
   for(i=0;(c=zf[i])!='\0';i++){ 
      if(c==' '){
         word=0;
        }
      else if(word==0){  
         word=1;
         num++;
        }//意思就是读到空格后才赋值word=0, 
    } 
   printf("there is %d words in this line;\n",num);
   return 0;
}
