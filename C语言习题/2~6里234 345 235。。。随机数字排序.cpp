#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	a=6;
	int i,j,k;
	int cnt=0;
	
	i=a;
	while(i<=a+3){
		j=a;
		while(j<=a+3){
			k=a;
			while (k<=a+3){
				if(i!=j && i!=k && j!=k ){
					cnt++;
					printf("%d%d%d",i,j,k);
					if(cnt==6){
						printf("\n");
						cnt = 0;
					}else{
						printf(" ");
					}
				}
				k++;
			}
			j++;
		}
		i++;
	}
 } 
