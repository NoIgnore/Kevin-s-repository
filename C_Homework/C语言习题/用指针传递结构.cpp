#include <stdio.h>
struct point{
		int x;
		int y;
};
struct point* getstruct(struct point*);
void output(struct point);
void print(const struct point *p);

int main(int argc, char const *argv[])
{	
	struct point y={0,0};
	getstruct(&y);
	output(y);
	output(*getstruct(&y));
	print(getstruct(&y));
}
struct point* getstruct(struct point *p)//struct point*表示返回一个指针  
{
	scanf("%d", &p->x);
	scanf("%d", &p->y);
//	p->y=12;
//	p->x=14; 
//	printf("输入的是12和14\n");
//	printf("输出的是-> ");
	printf("%d, %d\n",p->x, p->y);
	return p;
}
void output(struct point p)
{
  printf("%d, %d",p.x, p.y);
}
void print(const struct point *p)
{
	printf("%d, %d",p->x,p->y);
}
