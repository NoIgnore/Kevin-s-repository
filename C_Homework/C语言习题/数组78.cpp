#include <stdio.h>
int search (int key, int a[], int length);
int main(void)
{
	int a[]={2,4,6,1,7,3};
	{
		int i;
		printf("%lu\n", sizeof(a));
		printf("%lu\n", sizeof(a[1]));
		for( i=0; i<sizeof(a)/sizeof(a[1]);i++){
			printf("%d\t", a[i]);
		}
		printf("\n");
	}
	int x;
	int loc;
	printf("请输入一个数字:");
	scanf("%d", &x);
	loc=search(x,a,sizeof(a)/sizeof(a[0]));
	if (loc != -1){
		printf("%d在第%d个位置上\n" ,x,loc);
	} else{
		printf("%d doesn't exist\n",x);
	}
	return 0;
 } 
 int search(int key, int a[], int length)
 {
 	int ret = -1;
 	int i;
 	for (i=0; i< length; i++){
 		if (a[i]==key){
 			ret = i;
 			break;
		 }
	 }
	 return ret;
 }
