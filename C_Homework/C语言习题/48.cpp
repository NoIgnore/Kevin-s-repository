#include <stdio.h>
int main()
{
	int n=3;
	scanf("%d", &n);
	n=3;
//	//±éÀú100-999
    int i; 
	i=100;
	while (i<1000){
		int a;
		int j,k,l,sum,p;
		j=1 ;
		while(0<j<10){
			k=1;
			while(0<k<10){
				l=1;
				while(0<l<10){
					a=i;
                    sum=j*j*j+k*k*k+l*l*l;
                    p=100*j+10*k+l;
					if (a==sum){
						if (sum==p){
						printf("%d\n", a);
						}
					}
					l++;
				}
				k++;
			}
			j++;
		}
//		a=100*j+10*k+l;
//		sum=j^3+k^3+l^3;
//		if(a=sum){
//			printf("%d", a);
//}
		i++;
	}
	return 0;
 } 
