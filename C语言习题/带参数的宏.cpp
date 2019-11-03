#include<stdio.h>
#define R1(x) (x*57.29578)
#define R2(x) (x)*57.29578
//#define FORMAT "%f\n"

int main(int argc, char const *argv[])
{
	printf("%f\n", R1(5+2));//=5+2* 57.29578
	// Ó¦¸ÃÐ´³É #define R1(x) ((x)*57.29578)
	printf("%f\n", 180/R2(1));//=180/1 *57.29578 
	return 0;
} 
