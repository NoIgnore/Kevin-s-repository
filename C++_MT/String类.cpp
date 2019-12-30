#include<iostream>
using namespace std;

int main ()
{
	int k; 	
	cin >> k; 	
	if (k == 1) 	
	{ 		
		cout << "ture" << endl;
		return 0; 	
	} 	
	if (k <= 0)
	{
		cout << "false" << endl;
		return 0; 	
	}
	while(k%2==0)
	{
		k/=2;
	}
	cout<<(k==1?"true":"false")<<endl;
    return 0;
}