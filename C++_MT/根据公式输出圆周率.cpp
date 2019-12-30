#include<iostream>

const double FLAG=1E-8;
using namespace std;
int main(void)
{
	double l;
	int k = 1; 	
	int step = 0; 	
	double sum=0.00000000; 
	int n = 1; 	
	double u = 1.00000000; 
	while (true) 	
	{ 		
		if (k == 1) 		
		{ 			
			sum += u / n;
			k = 0; 		
		} 		
		else if (k == 0) 		
		{ 			
			sum -= u / n;
			k = 1; 		
		} 		
		l = u / n > 0 ? u / n : (-(u / n));
		step++; 		
		if (l < 1e-8)
		{ 			
			break; 		
		} 		
		n += 2; 	
	} 	
	printf("steps=%d PI=%.5f", step, 4 * sum);
	return 0;
}
