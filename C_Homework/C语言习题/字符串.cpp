#include <stdio.h>
int main()
{
	
//	char w[]={'h','j','k','u','g','\0'};
//	char c[]={'h','t','k','f','j','\0'};
//	int i=0;
//	while (w[i] !='\0' && c[i] !='\0'){
//	    if(w[i]==c[i]){
//	    	printf("%s", w[i] );
//		}
//		i++;
//	}
    char x[]="programmng";
    char y[]="Fortran";
    int i=0;
    while (x[i] !='\0'&& y[i] !='\0'){
       if(x[i]==y[i]){
       	printf("%c",x[i++]);
	   }else{
	   i++;
	   } 
       
    }
	return 0;
 } 
