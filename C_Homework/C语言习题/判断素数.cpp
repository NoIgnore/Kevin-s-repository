#include <stdio.h>
int main()
{
	int  n;
    scanf("%d", &n);
    int isPrime = 1;
    if(n>=2147483647){
    	isPrime = 1;
    	printf("yes");
	}
		int k;
		for ( k=2; k<n; k++){//�� kд��<=��n/2���Ϳ��Բ������״�����hhhh 
			if (n%k==0){
				isPrime = 0;
				break;
			}
		}
    if(n<=3){
    	printf("error");
	}
    if( n>3 && n<2147483647){
	if( isPrime ){
    	printf("yes");
	   }else {
		printf("no");
	   }
    }
    
    return 0;
}
