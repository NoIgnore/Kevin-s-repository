#include <iostream>

using namespace std;

class Date {
private:

	int year;

	int month;

	int day;
public:

	Date(int y = 1996, int m = 1, int d = 1)
	{
		day = d;
		month = m;

		year = y;

		if (m > 12 || m < 1) {

			month = 1;

		}

		if (d > days(y, m)) {

			cout << "Invalid day!" << endl;

			day = 1;

		}

	};

	int days(int y, int m);

	void display()

	{

		cout << year << "-" << month << "-" << day << endl;

	}


};
ostream& operator<<(ostream& os, Date c)
{

	c.display();
	return os;
}
int Date::days(int y, int m)
{
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else if (m != 2)
	{
		return 31;
	}
	return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
}
int main() {

	int y, m, d;

	cin >> y >> m >> d;

	Date dt(y, m, d);

	cout << dt;

	return 0;

}