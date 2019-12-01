#include<stdio.h>
double jieceng(double a, double b)
{
	double i;
	if(b==1){
		a=1;
	}else{
		double t=1;
		for(i=b;i>0;i--){
			a=i;
			t*=a;
		}
		b=t;
	}
	return b;
}
double cifang(double a, double b)
{
	double i,t=1;
	for(i=0;i<b;i++){
		t*=a;
	}
	a=t;
	return a;
}
//# include <stdio.h>
//int main()
//{
//	int a,b;
//	scanf("%d %d",&a,&b);
//	int i,t=1;
//	for(i=0;i<b;i++){
//		t *= a;
//	}
//	a=t;
//	printf("%d",a);
//	return 0;
//}
int main()
{
//	int f,q;
//	f=jieceng(1,5);
//	q=cifang(3,2);
//	printf("%d %d", f, q);
//	return 0;
    double x,n;
    scanf("%lf %lf" , &x, &n);
    double i,s,p,q;
    double t=1;
    double sum=1;
    double j=1;
    if(n<=0){
    	printf("error");
	}else{
      for(i=1;i<=n && j<=n; i++){
    	p=cifang(x,j);
    	q=jieceng(1,i);
    	s=p/q;
    	j++;
    	sum += s;
	}
	printf("在%.0f的阶层计算内e^%.0f = %.6f", n,x,sum);
   }
	return 0;
 } 
