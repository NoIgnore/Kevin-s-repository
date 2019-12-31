#include <iostream>
using namespace std;
int main()
{
	int year, month, day;
	int sum = 0, i, j;

	cin >> year >> month >> day;
//....
    month--;
	while (month > 0)
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			i = 30;
		}
		else if (month != 2)
		{
			i = 31;
		}
		else 
		{
			i = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28; 		
		}
		sum += i;
		month--;
	}
	sum = sum + day;
//....
	cout << sum << endl;
	return 0;
}
