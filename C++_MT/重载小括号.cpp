/*
重载运算符()，使之能够方便地为Time对象赋值，你的填空需要注意单位换算。
如：
输入：1 2 3
输出：1:2:3

输入：1 2 61
输出：1:3:1

输入：1 61 61
输出：2:2:1
*/
#include<iostream>
#include<cstring>
using namespace std;
class Time {
private:
	int hour, minute, second;
public:
	Time(int h = 0, int m = 0, int s = 0)
	{
		operator()(h, m, s);
	}
	void echoTime()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	//............
	Time operator()(int h, int m, int s)
	{
		hour = h, minute = m, second = s;
		if (second >= 60)
		{
			minute += second / 60;
			second = second % 60;
		}
		if (minute >= 60)
		{
			hour += minute / 60;
			minute = minute % 60;
		}
		if (hour >= 24)
		{
			hour = hour % 24;
		}
		return *this;
	}
};

int main()
{
	int h, m, s;
	cin >> h >> m >> s;
	Time time;
	time(h, m, s);
	time.echoTime();
	return 0;
}