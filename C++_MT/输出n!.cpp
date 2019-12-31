#include<iostream>
using namespace std;

int main ()
{
		int i = 1; 	
		int j; 	
		cin >> j; 	
		if (j >= 12)j = 12; 	
		if (j == 0) 	
		{ 		
			cout << "0" << "!=" << 1 << endl;
			return 0; 	
		} 	
		int t = j; 	
		while (j>0) 
		{ 		
			i *= j; 
			j--; 	
		} 	
		cout << t << "!=" << i << endl; 	
		return 0;
}

