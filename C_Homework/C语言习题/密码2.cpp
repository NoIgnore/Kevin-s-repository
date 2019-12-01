#include<stdio.h>
//#define N 256
int main() 
{ 
  
  char str[21]={'\0'};
  int i;
  scanf("%s",str);
  // i=0; 
  // while ( 1 ) {
  //   str[i]=getchar(); if ( str[i]==10 ) break;
  //    i++; if ( i>=N-1 ) break;
  // }
  //str[i]=0;
  //ASDZXCASDA
  i=0;
  while ( str[i]!=0 ) {
    if ( str[i]>='a' && str[i]<='z' ) {
	    str[i]=(str[i]-'a'+4)%26+'a';
    }else if ( str[i]>='A' && str[i]<='Z' ) {
	    str[i]=(str[i]-'A'+4)%26+'A';
        i++;
	}
  }
  
  printf("%s\n",str);
}
