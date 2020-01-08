#ifndef Bullet_h
#define Bullet_h

#include"acllib.h"
#include"CusrSprite.h"

class BulletSprite :public CusrSprite
{
	public:
		BulletSprite(BulletSprite &);
		BulletSprite(char const *name,int x,int y,int dx,int dy,int w,int h,int wWidth,int wHeight);
		~BulletSprite(void);
		void move();
		int collision(CautoSprite &a);
		void drawScale(int w,int h);
};

#endif
