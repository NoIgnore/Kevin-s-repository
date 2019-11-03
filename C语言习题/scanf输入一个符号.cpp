#include <stdio.h>
int main()
{
	int z,m;
	scanf("%d/%d", &z, &m);
	
	int a = z;
	int b = m;
	int t;
	while ( b>0 ){
		t= a%b;
		a=b;
		b=t;
	} 
	printf("%d/%d\n", z/a, m/a);
	return 0;
}
