#include <iostream>
using namespace std;
class Date {
public:
	Date(int y = 1996, int m = 1, int d = 1) {
		day = d;
		month = m;
		year = y;
		if (m > 12 || m < 1)
		{
			month = 1;
		}
		if (d > days(y, m))
		{
			cout << "Invalid day!" << endl;
			day = 1;
		}
	};
	int days(int y, int m);
	friend ostream& operator<<(ostream& os, const Date& c);
	void display() {
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};
int Date::days(int y, int m)
{
	if (m == 4 || m == 6 || m == 9 || m == 11){return 30;}
	else if (m != 2){return 31;}
	return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
}
ostream& operator<<(ostream& os, const Date& c)
{
	os << c.year << "-" << c.month << "-" << c.day << endl;
	return os;
}
int main()
{
	int y, m, d;
	cin >> y >> m >> d;
	Date dt(y, m, d);
	cout << dt;
	return 0;
}
// 你需要实现运算符 << 的重载， 输出日期的格式参见display方法。
// 实现Date对象的days方法，该方法返回指定年月有多少天，如days(2001,1),返回31.

// 最终Date类的使用方式如下，在你的代码中除了完成Date函数还需包含以下main函数：

// int main(){
//      int y,m,d;
// 	 cin>>y>>m>>d;
// 	 Date dt(y,m,d);
// 	 cout<<dt;
// 	 return 0;
// }

// 例如,输入：
// 2013 2 1回车
// 输出：
// 2013-2-1回车