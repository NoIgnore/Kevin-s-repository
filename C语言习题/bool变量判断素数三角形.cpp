#include<stdio.h>
//#include<math.h>
int D(int a)
{	
//	for( i=2; i<a; i++){
		int isPrime = 1;//isprime要写里面因为循环一次就重新赋值成1一次！！！ 
		int k;
		for ( k=2; k<a; k++){
			if (a%k==0){
				isPrime = 0;
				break;
			}
		}
//		//判断i是否为素数
//		if (isPrime==1){
//			printf("%d,",i);
//		} 
//	}
	
	return isPrime;
} 
int main()
{
	int n,m,a,b,i,j,r3=0;
	printf("666\n") ;
	scanf("%d %d",&n,&m);
	for(a=2;a<=m;a++){
//	for(i=2;i<=a;i++)
//	{
	   if(D(a)){//continue;
//  else {
	        for(b=a;b<=m;b++){
	              if (D(b)){
	                 if(a+b>n && a+n>b){
				      r3=r3+1;
				     }//else continue;
				  }//else continue;
	        }
	    }// else continue;
    }  
    //}
 
   printf("%d",r3);
   return 0;
}
//#include<stdio.h>
//bool IsPrime(int val)
// {
// 	int i;
// 	for (i=2;i<val;i++)
// 	{
// 		if(val%i == 0) break;
//	}
//	if(i == val||val==2||val==3) return true;
//    else  return false;
// }
//int main()
//{
//	int n,m,a,b,r3=0;
//    scanf("%d %d",&n,&m);
//    for(a=2;a<=m;a++)
//    {
//    	if(IsPrime(a))
//    	{
//    		for(b=a;b<=m;b++)
//    		{
//    			if(IsPrime(b))
//    			{
//    				if(a+b>n&&a+n>b){r3=r3+1;}
//    				else continue;
//				}
//				else continue;
//			}
//		}
//		else continue;
//	}
//	printf("%d",r3);
//	return 0;
//}

