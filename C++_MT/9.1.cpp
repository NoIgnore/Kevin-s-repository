#include <iostream>
using namespace std;
class Point {
public:
	Point(float xx, float yy) {
		x = xx;
		y = yy;
	}
private:
	float x;
	float y;
};

class Rectangle :public Point {
public:
	Rectangle(float xx, float yy, float w, float h);
	float Area();
private:
	float width;
	float high;
};

class Circle :public Point {
public:
	Circle(float xx, float yy, float r);
	float Area();
private:
	float radius;
};

Rectangle::Rectangle(float xx, float yy, float w, float h):Point(xx, yy)
{
	//Point(xx, yy);
	width = w;
	high = h;
}
float Rectangle::Area()
{
	return width * high;
}
Circle::Circle(float xx, float yy, float r):Point(xx, yy)
{
	//Point(xx, yy);
	radius = r;
}
float Circle::Area()
{
	 float pi = (float)3.14;
	return radius * radius * pi;
}