#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   void *p;
   int cnt=0;
   while ((p=malloc(100*1024*1024))){//���(p=malloc(100*1024*1024))��ַ�������while������ 
   	cnt++;
   }
   printf("������%d00MB�Ŀռ�\n", cnt);
    free (p); 
   return 0;
}
