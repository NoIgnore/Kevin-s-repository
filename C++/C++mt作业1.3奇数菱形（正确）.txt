#include <iostream>
using namespace std;
void printStar(int n);
int main()
{
	int n ;
	cin>>n;
	if (n % 2 == 0 || ((n<1) || (n>80))) {
		cout << "error";
	}
	else {
		printStar(n);
	}
	return 0;
}
void printStar(int n) {
	int  h, k, j;
	for (k = 1; k <= (n + 1)/2 ; k++) {
		for (h = 1; h < k; h++) {
			cout << " ";
		}
		for (h = 1; h <= (n - (k-1)*2) ; h++) {
			cout << "*";
		}
		cout << endl;
	}
}
/*
输入9有5行
*********    0个空格（第1行）n*
 *******	 1个空格（第2行）n-2*
  *****		 2个空格（第3行）n-4*
   ***		 3个空格（第4行）n-6*
	*		 4个空格（第5行）n-8*
*/
