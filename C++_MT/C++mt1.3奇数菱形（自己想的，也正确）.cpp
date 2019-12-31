#include <iostream>
using namespace std;
void printStar(int sr);
int main()
{
	int s = 9;
	//cin>>n;
	printStar(s);
	return 0;
}
void printStar(int sr) {
	int n, d, k;
	d = (sr + 1) / 2;
	k = 0;
	int u = 0;
	for (n = 1; n <= d; n++) {
		if (u == 1) {
			k += 2;
		}
		if (k < 1) {
			for (int srr = 1; srr <= sr; srr++) {
				cout << "*";
			}
			u = 1;
			cout << endl;
		}
		else {
			for (int kk = 1; kk <= (k / 2); kk++) {//之前就是因为把kk++写成k++,搞得我。。。
				cout << " ";
			}
			for (int xx = 1; xx <= (sr - ((n - 1) * 2)); xx++) {
				cout << "*";
			}
			cout << endl;
		}

	}
}

/*
输入9有5行
*********    0+0个空格（第1行）
 *******	 1+1个空格（第2行）
  *****		 2+2个空格（第3行）
   ***		 3+3个空格（第4行）
	*		 4+4个空格（第5行）
*/