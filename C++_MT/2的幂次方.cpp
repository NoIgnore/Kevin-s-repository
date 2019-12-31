#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	if (n <= 0)
	{
		cout<< "false"<<endl;
	}
	if ((n&(n - 1)) == 0)
	{
		cout<<"true"<<endl;
	}
	else cout<<"false"<<endl;
	return 0;
}