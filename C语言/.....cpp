#include <stdio.h>
int main()
{
	int price;
	int bill;
	printf("请输入金额（元）:");
	scanf("%d", &price);
	printf("请输入票面（元）；");
	scanf("%d", &bill);
	if (bill>=price){
	printf("应该找您%d元\n", bill-price) ;
}
    printf("钱不够你买尼马呢！"); 
	return 0;
 } 
