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
//����һ���ַ���ͳ�������ж��ٵ��ʣ�����֮���ÿո�ָ���
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
        }//��˼���Ƕ����ո��Ÿ�ֵword=0, 
    } 
   printf("there is %d words in this line;\n",num);
   return 0;
}
