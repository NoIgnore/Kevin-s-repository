#include<stdio.h>
#include<math.h>
int main()
{
//	int i;
//	int isPrime=1;
//	int k;
//	for(i=3;i<100;i++){
//		for ( k=2;k<i; k++){//把 k写成<=（n/2）就可以不用作弊代码了hhhh 
//			if (i%k==0){
//				isPrime=0;
//				break; 
//			}
//			
//		}
//	
//		if (isPrime==1){
//			printf("%d\n",i);
//		}
//		}
////	} k<sqrt((float)i)
    int i;
	
	for( i=2; i<=200; i++){
		int isPrime = 1;//isprime要写里面因为循环一次就重新赋值成1一次！！！ 
		int k;
		for ( k=2; k<i; k++){
			if (i%k==0){
				isPrime = 0;
				break;
			}
		}
		//判断i是否为素数
		if (isPrime==1){
			printf("%d,",i);
		} 
	}
	
	return 0;
} 
