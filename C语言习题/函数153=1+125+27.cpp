#include<stdio.h>
int find(int n)
{
	int fh,fw,count=0;
	int b,s,g,t;
	if(n<100 || n>999){
		count=0;
	}else{
		for(fw=100;fw<=n;fw++){
			b=fw/100;
			t=fw/10;
			s=t%10;
			g=fw%10;
			if((b*b*b + s*s*s + g*g*g)==fw ){
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int n;
	scanf("%d",&n);
	find(n);
	printf("%d", find(n));
	return 0;
}
