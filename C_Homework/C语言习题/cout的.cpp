#include <stdio.h>
#include <iostream>
int main()
{
   int i,j;
   for(i =0;i<100;i++){
       j = i*10 + 6 ;
	 if(j%3==0 && j<100)continue;
	 cout<<j;
   }
   return 0;

 }
