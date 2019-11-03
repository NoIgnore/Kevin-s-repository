# include <stdio.h>
int cf(int a, int b)
{
	int i,t=1;
	for(i=0;i<b;i++){
		t*=a;
	}
	a=t;
	return a;
}
int main()
{
	int n;
	int a,b,c,d,e;
	scanf("%d",&n);
	a=cf(n,1);
	b=cf(n,2);
	c=cf(n,3);
	d=cf(n,4);
	e=cf(n,5);
	printf("%d %d %d %d %d\n",  a,b,c,d,e);
	return 0;
}
