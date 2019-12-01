#include <stdio.h>
struct point{
		int x;
		int y;
};
struct point getstruct(void);
void output(struct point);

int main(int argc, char const *argv[])
{
	
	struct point y={0,0};
	y= getstruct();
	output(y);
}
struct point getstruct(void)
{
	struct point p;
	scanf("%d", &p.x);
	scanf("%d", &p.y);
	printf("%d, %d\n",p.x, p.y);
	return p;
}
void output(struct point p)
{
  printf("%d, %d",p.x, p.y);
}
   
