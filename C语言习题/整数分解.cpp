#include <stdio.h> 
int main()
{
	int x;
//	scanf("%d", &x);
	x =13425;
	do {
		int d= x%10;
		printf("%d", d);//�����%d�����пո����һ����Ҳ�����ո�
		if (x>9){
			printf(" ");
		} 
		x/=10;
	} while (x>0);
	return 0;
}
