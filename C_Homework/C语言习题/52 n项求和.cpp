#include <stdio.h> 
int main()
{
	int n;
	double z,m ;
	double sum =0.0;
	int i;
	double t;
	scanf("%d", &n);
	z=2;
	m=1;
	for (i=1; i<=n;i++){
		sum += z/m ;
		t =z ;
		z +=m ;
		m = t; 
	}
	printf("%f %f\n", z,m ) ;
	printf("%.2f\n", sum) ;
	
	return 0;
}
