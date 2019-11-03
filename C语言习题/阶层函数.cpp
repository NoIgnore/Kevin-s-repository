#include<stdio.h>
int jc(int b)
{
    
	   int i;
	//scanf("%d",&b);
//	if(b>0)
//{
//	if(b==1){
//		b=1;
//	}else{
		int t=1;
		for(i=b;i>0;i--){
			t*= i;
		}
		b=t;
//		printf("%d",b);
//	}
//}else{
//	printf("error");
//}
	return b;
}
int main()
{
	int b,c;
	scanf("%d",&b);
//	c=jc(b);
	printf("%d",jc(b));
	return 0;
}
